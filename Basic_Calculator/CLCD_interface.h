/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 5 Feb 2023                 *****************/
/******* Version   : 1.0.0                      *****************/
/******* File Name : CLCD_interface.h           *****************/
/****************************************************************/
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

/**
 * @brief Enum defining LCD operation modes.
 */
typedef enum {
    LCD_4BitMode = 4, /**< 4-bit mode */
    LCD_8BitMode = 8  /**< 8-bit mode */
} LCD_Mode_t;

/**
 * @brief Structure representing LCD pin configuration.
 */
typedef struct {
    uint8_t LCD_PortId: 2;  /**< Port ID for the LCD pin */
    uint8_t LCD_PinId: 4;   /**< Pin ID for the LCD pin */
    uint8_t :2;             /**< Padding */
} LCD_PinConfig_t;

/**
 * @brief Structure representing LCD configuration.
 */
typedef struct {
    uint8_t mode;                /**< 8-bit or 4-bit mode indicator */
    LCD_PinConfig_t dataPins[8]; /**< Maximum pins for 8-bit mode */
    LCD_PinConfig_t rsPin;       /**< RS pin */
    LCD_PinConfig_t rwPin;       /**< R/W pin */
    LCD_PinConfig_t enablePin;   /**< Enable pin */
} LCD_Config_t;

/**
 * @brief Initializes the LCD module.
 *
 * This function initializes the LCD module according to the provided configuration.
 * It sets the direction of control pins (enable, rs, rw) and data pins based on the
 * mode specified in the configuration.
 *
 * Example usage:
 * @code
 * LCD_Config_t lcd1;
 * lcd1.mode = LCD_4BitMode;
 * for (u8 i = 0; i < 4; i++) {
 *     lcd1.dataPins[i].LCD_PortId = DIO_PORTA;
 *     lcd1.dataPins[i].LCD_PinId = DIO_PIN3 - i;
 * }
 * lcd1.enablePin.LCD_PortId = DIO_PORTA;
 * lcd1.enablePin.LCD_PinId = DIO_PIN4;
 * lcd1.rsPin.LCD_PortId = DIO_PORTA;
 * lcd1.rsPin.LCD_PinId = DIO_PIN5;
 * LCD_Init(&lcd1);
 * @endcode
 *
 * @param config Pointer to the configuration structure containing initialization parameters.
 */
void LCD_Init(const LCD_Config_t *config);

/**
 * @brief Sends a command to the LCD module.
 *
 * This function sends a command to the LCD module based on the provided configuration.
 * It sets the RS pin to low for command mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the command.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] command The command to be sent to the LCD.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void LCD_SendCommand(const LCD_Config_t *config, uint8_t command);

/**
 * @brief Sends a character to the LCD module for display.
 *
 * This function sends a character to the LCD module based on the provided configuration.
 * It sets the RS pin to high for data mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the character.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] character The character to be sent to the LCD for display.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void LCD_SendChar(const LCD_Config_t *config, uint8_t character);

/**
 * @brief Sends a null-terminated string to the LCD for display.
 *
 * This function sends a null-terminated string to the LCD module for display
 * based on the provided configuration. It iterates through the characters of
 * the string and sends each character to the LCD using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] string Pointer to the null-terminated string to be displayed on the LCD.
 * @note This function assumes that the required GPIO module and LCD character functions have been initialized separately.
 */
void LCD_SendString(const LCD_Config_t *config, const uint8_t *string);

/**
 * @brief Displays a double-precision floating-point number on the LCD.
 *
 * This function displays a double-precision floating-point number on the LCD based on
 * the provided configuration. It separates the integer and fractional parts of the number,
 * displays the integer part directly, and then displays the fractional part with three decimal
 * places using LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The double-precision floating-point number to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void LCD_SendNumber(const LCD_Config_t *config, double number);

/**
 * @brief Displays the integer part of a signed integer on the LCD.
 *
 * This function displays the integer part of a signed integer value on the LCD based on
 * the provided configuration. It separates the digits of the integer part and displays
 * them sequentially using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The signed integer value whose integer part is to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void LCD_SendIntegerNumber(const LCD_Config_t *config, s32 number);

/**
 * @brief Clears the display of the LCD.
 *
 * This function sends a command to the LCD module based on the provided configuration
 * to clear the display content and reset the cursor to the home position (the first row
 * and the first column).
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void LCD_Clear(const LCD_Config_t *config);

/**
 * @brief Moves the cursor of the LCD to a specific position.
 *
 * This function moves the cursor of the LCD module based on the provided coordinates
 * (x and y) within the screen bounds specified by the LCD configuration.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] x The x-coordinate (column) on the LCD (0 to 15 for a 16-column display).
 * @param[in] y The y-coordinate (row) on the LCD (0 or 1 for a two-row display).
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void LCD_GoToXYPos(const LCD_Config_t *config, uint8_t x, uint8_t y);

#endif /**< CLCD_INTERFACE_H */

