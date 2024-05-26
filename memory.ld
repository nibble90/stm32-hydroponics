_end_of_stack = ORIGIN(RAM) + LENGTH(RAM);

ENTRY(Reset_Handler)

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 32K
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 10K
}

SECTIONS
{
    .isr_vector : { KEEP(*(.isr_vector))} > FLASH
    .text : { *(.text*) } > FLASH
    .rodata : { *(.rodata*) } > FLASH

    .data : {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM AT > FLASH
    _sidata = LOADADDR(.data);

    .bss : {
        _sbss = .;
        *(.bss SORT(.bss.*) COMMON)
        _ebss = .;
    } > RAM

    . = ALIGN(4);
}