
/**
 \ingroup Function for BLE protocol By: Firas Faham
 \brief  Private function to split a Byte (8bit) value into (2) (4bit) Nibble values.  \n
This function is used break a (2) digit, 8bit value into pieces and load it back into
the payload as a 'char' representation of the number presented as a hex value.
 \return void \n
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

BLE_SplitByte(char* , int8_t );


int main()
{
    
    char payload[3];   //  message elements used to send / receive BLE packet
    //char button = 0x10; // 0x01 OFF and 0x00 ON  Button pressed at Client side
    int8_t button = 0x07; // 0x01 OFF and 0x00 ON

     printf("\nBLE_SplitByte 2");
     printf("\n======================\n\n");


printf("initial payload is d and last NULL is V and button is  %x \n\n ", button);

for (int i=-4; i<= 3; i++){
printf("\nPayload %i   %p %C  ",i, (payload-i), *(payload-i)   );
}
printf("\n======================\n\n");


    *payload = 'd';    // Original payload is NULL '\0'
    BLE_SplitByte(payload, button);


for (int i=-4; i<= 3; i++){
printf("\nPayload %i   %p %X %c  ",i, (payload-i), *(payload-i), *(payload-i)   );

if(i == -3) {printf(" < NULL");}

}

    return 0;
}


// Store the 4 bits components of 8 bits message in memory locations.
// Those 2 of 4 bits characters are then used to control the device
BLE_SplitByte(char* payload, int8_t value)
{
    payload += strlen(payload);
    *payload++ = (value >> 4);    // Operate with * then increment address
   // *payload++ = (value & 0xF);
    *payload++ = (value);
    *payload = 'V';   // Original is '\0'
}


