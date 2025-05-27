#include<c64.h>
#include<conio.h>

unsigned char * const sprite_data=0x2000;
unsigned char * const sprite0_ptr=0x07f8;

void create_sprite_data() {
    unsigned int i;

    for(i=0; i<10*3; i+=3) {
        sprite_data[i]=0xff;
        sprite_data[i+1]=0xf0;
        sprite_data[i+2]=0x00;
    }

    for(i=3*10; i<20*3; i+=3) {
        sprite_data[i]=0x00;
        sprite_data[i+1]=0x0f;
        sprite_data[i+2]=0xff;
    }

    sprite_data[60]=0x00;
    sprite_data[61]=0x00;
    sprite_data[62]=0x00;
}

void init_sprite() {
    VIC.spr0_color=COLOR_WHITE;
    *sprite0_ptr=((unsigned int)sprite_data)/64;
    VIC.spr_ena|=0x01;
}

void move_sprite() {
    unsigned int x;
    unsigned char y;
    for(y=60; y<200; y+=10) {
        VIC.spr0_y=y;
        for(x=0; x<360; x++) {
            waitvsync();
            VIC.spr0_x=x;
            if(x>255) {
                VIC.spr_hi_x|=0x01;
            } else {
                VIC.spr_hi_x&=0xfe;
            }
        }
    }
}

int main(void) {
    clrscr();
    VIC.bgcolor0=COLOR_BLACK;
    VIC.bordercolor=COLOR_BLUE;

    create_sprite_data();
    init_sprite();
    move_sprite();

    return 0;
}
