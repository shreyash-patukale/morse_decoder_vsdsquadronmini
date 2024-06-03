#include "debug.h"
#include "ssd1306.h"
#include "ch32v00x.h"

char morseSequence[10];
int morseIndex = 0;

//GPIO
void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // Enable clock for GPIO port D (Assuming the button is connected to port D)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // Enable clock for GPIO port C (Assuming the light is connected to port C)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Button pin configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4; // Buttons connected to pins 2, 3, and 4 of port D
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input with pull-up resistor
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Light pin configuration
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; // Assuming light is connected to pin 6 of port C
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Output push-pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Maximum speed
    GPIO_Init(GPIOC, &GPIO_InitStructure); // Corrected to use GPIOC instead of GPIOD
}
//STARTUP FUNC
void Startup(void)
{
    SystemCoreClockUpdate();
    Delay_Init();
    OLED_Init();
    OLED_Fill(0);
    OLED_UpdateScreen();

    //"TEAM AYODHYA"
    OLED_GotoXY(40, 13);
    OLED_Puts("TEAM", &Font_11x18, 1);
    OLED_GotoXY(25, 35);
    OLED_Puts("AYODHYA", &Font_11x18, 1);
    OLED_UpdateScreen();
    Delay_Ms(2000);

    OLED_Fill(0);
    OLED_UpdateScreen();

    //"PRESENTS"
    OLED_GotoXY(38, 28);
    OLED_Puts("Presents", &Font_7x10, 1);
    OLED_UpdateScreen();
    Delay_Ms(1500);

    OLED_Fill(0);
    OLED_UpdateScreen();

    //"MORSE"
    OLED_GotoXY(8, 4);
    OLED_Puts("MORSE CODE", &Font_11x18, 1);
    OLED_GotoXY(25, 24);
    OLED_Puts("DECODER", &Font_11x18, 1);
    OLED_GotoXY(0, 50);
    OLED_Puts("w/VSDSquadron Mini", &Font_7x10, 1);
    OLED_UpdateScreen();
    Delay_Ms(4000);

    OLED_Fill(0);
    OLED_UpdateScreen();
}
//SELM FUNC
void SelectMode(void)
{
    OLED_Fill(0); // Clear the screen
    OLED_UpdateScreen();

}
char decodeMorse(const char* morse)
{
    // MAPPING
    if (strcmp(morse, ".-") == 0) return 'A';
    if (strcmp(morse, "-...") == 0) return 'B';
    if (strcmp(morse, "-.-.") == 0) return 'C';
    if (strcmp(morse, "-..") == 0) return 'D';
    if (strcmp(morse, ".") == 0) return 'E';
    if (strcmp(morse, "..-.") == 0) return 'F';
    if (strcmp(morse, "--.") == 0) return 'G';
    if (strcmp(morse, "....") == 0) return 'H';
    if (strcmp(morse, "..") == 0) return 'I';
    if (strcmp(morse, ".---") == 0) return 'J';
    if (strcmp(morse, "-.-") == 0) return 'K';
    if (strcmp(morse, ".-..") == 0) return 'L';
    if (strcmp(morse, "--") == 0) return 'M';
    if (strcmp(morse, "-.") == 0) return 'N';
    if (strcmp(morse, "---") == 0) return 'O';
    if (strcmp(morse, ".--.") == 0) return 'P';
    if (strcmp(morse, "--.-") == 0) return 'Q';
    if (strcmp(morse, ".-.") == 0) return 'R';
    if (strcmp(morse, "...") == 0) return 'S';
    if (strcmp(morse, "-") == 0) return 'T';
    if (strcmp(morse, "..-") == 0) return 'U';
    if (strcmp(morse, "...-") == 0) return 'V';
    if (strcmp(morse, ".--") == 0) return 'W';
    if (strcmp(morse, "-..-") == 0) return 'X';
    if (strcmp(morse, "-.--") == 0) return 'Y';
    if (strcmp(morse, "--..") == 0) return 'Z';
    return '?'; //
}

//"DEC"
void Decoder(void)
{
    OLED_Fill(0);
    OLED_UpdateScreen();
    OLED_GotoXY(5, 5);
    OLED_Puts("ENTER MORSE CODE:", &Font_7x10, 1);
    OLED_UpdateScreen();

    int xPos = 5;
    int yPos = 20;

    while (1)
    {
        if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == Bit_RESET)
        {
            // Button 1 is pressed, add dot
            morseSequence[morseIndex++] = '.';
            OLED_GotoXY(xPos, yPos);
            OLED_Puts(".", &Font_7x10, 1);
            xPos += 6; // Move to the next position
            OLED_UpdateScreen();
        }
        else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4) == Bit_RESET)
        {
            // Button 2 is pressed, add dash
            morseSequence[morseIndex++] = '-';
            OLED_GotoXY(xPos, yPos);
            OLED_Puts("-", &Font_7x10, 1);
            xPos += 6; // Move
            OLED_UpdateScreen();
        }
        else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2) == Bit_RESET)
        {
            // Button 3 is pressed, decode Morse code
            morseSequence[morseIndex] = '\0'; // Null-terminate the sequence
            char decodedChar = decodeMorse(morseSequence);
            OLED_GotoXY(5, 35);
            char displayStr[2] = {decodedChar, '\0'};
            OLED_Puts("DECODED TEXT: ", &Font_7x10, 1);
            OLED_Puts(displayStr, &Font_11x18, 1);
            OLED_UpdateScreen();
            morseIndex = 0;
            xPos = 5;
            memset(morseSequence, 0, sizeof(morseSequence)); // Clear the sequence
            if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2) == Bit_RESET)
            {
                Decoder();
            }
        }
        Delay_Ms(50);
    }
}
int main(void)
{
    Startup();
    SelectMode();

    GPIO_Config(); // Call GPIO

    while (1)
    {
        Decoder();
        Delay_Ms(1000);
    }
}
