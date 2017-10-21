/*
* kernel.c
*/
void kmain(void)
{
    const char *str = "Mikaels Kernel (MiKe)";
    char *vidptr = (char*)0xb8000; //video mem begins here.
    unsigned int i = 0;
    unsigned int j = 0;

    /* this loop clear the screen
    *  there are 25 lines of each 80 columns, each element takes 2 bytes */
    while(j < 80 * 25 * 2){
        /*  blank character*/
        vidptr[j] = ' ';
        /*  attribute byte - light grey on black screen*/
        vidptr[j+1] = 0x07;
        j = j + 2;
    }

    j = 0;

    /*  this loop writes the string to the video memory*/
    while(str[j] != '\0'){
        /*  the character's ascii */
        vidptr[i] = str[j];
        vidptr[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
return;
}