/*============================================================================*/
/*
 * author: A.Zuckovs
 * e-mail: andrejs.design@gmail.com
 * version: V1.0
 */
/*============================================================================*/
/* msSerial_V1.h*/
#ifndef MSF_SERIAL_V1_0_h
#define	MSF_SERIAL_V1_0_h
//..............................................................................


/* MSF -> Meteo Shield Frame */
#define MSF_BUFFER_SIZE            32

#define MSF_RX_NOT_COMPLETE        0
#define MSF_RX_COMPLETE            1
#define MSF_TX_NOT_COMPLETE        0
#define MSF_TX_COMPLETE            1

#define MSF_FRAME_END          		'\n'                                        

#define MSF_FRAME_START            	'#'
#define MSF_TEXT_SEPERATOR      	'^'                                         // text or commentary
#define MSF_DATA_SEPERATOR_0    	'.'
#define MSF_DATA_SEPERATOR_1    	':'

#define MSF_RX_ENABLE          		1

#define MSF_BAUD_RATE_1200         	0                                  			// In V1 not supported
#define MSF_BAUD_RATE_2400         	1                                           // In V1 not supported
#define MSF_BAUD_RATE_4800         	2                                           // In V1 not supported
#define MSF_BAUD_RATE_9600         	3                                           // In V1 not supported
#define MSF_BAUD_RATE_14400        	4                                           // In V1 not supported
#define MSF_BAUD_RATE_19200        	5                                           // In V1 not supported
#define MSF_BAUD_RATE_57600        	6                                           // In V1 not supported
#define MSF_BAUD_RATE_115200       	7                                           // Default V1
//..............................................................................
/* MS FRAME FORMAT
 *
 * #.CMD.VARIABLE.CODE:VALUE\r\n
*/
/* CMD */
#define MSF_CMD_R          'R'     // READ
#define MSF_CMD_S          'S'     // SET
#define MSF_CMD_A          'A'     // ANSWER

/* VARIABLE */                 	// VARIABLE number
#define MSF_V_TEMPERATURE  	'T' // 0
#define MSF_V_HUMIDITY     	'H' // 1
#define MSF_V_LIGHT        	'L' // 2
#define MSF_V_PRESSURE     	'P' // 3
#define MSF_V_CO2_I        	'Z' // 4
#define MSF_V_CO2_A        	'C' // 5
#define MSF_V_ANALOG       	'A' // 6	In V1 not supported
#define MSF_V_SOUND_I      	'V' // 7
#define MSF_V_SOUND_A      	'S' // 8

#define MSF_V_GPIO         	'G' // 9
#define MSF_V_EEPROM       	'E' // 10
#define MSF_V_TIME         	'X' // 11
#define MSF_V_DATE         	'D' // 12
#define MSF_V_DELAY        	'Q' // 13
#define MSF_V_STATUS       	'@' // 14
#define MSF_V_LED          	'I' // 15
#define MSF_V_OLED         	'O' // 16
#define MSF_V_RECORD       	'R' // 17

#define MSF_V_BOOTLOADER   	'B' //	In V1 not supported
#define MSF_V_DEVICE       	'Y' // Device

#define MSF_V_N           	'N' // No satch VARIABLE
#define MSF_V_ERROR     	'?' // Unknown VARIABLE

#define P_TEMPERATURE   0
#define P_HUMIDITY      1
#define P_LIGHT         2
#define P_PRESSURE      3
#define P_CO2_I         4
#define P_CO2_A         5
#define P_ANALOG        6
#define P_SOUND_I       7
#define P_SOUND_A       8
#define P_TIME          9
#define P_CALENDAR      10

#define P_GPIO          11
#define P_EEPROM        12
#define P_DELAY         13
#define P_STATUS        14
#define P_LED           15
#define P_OLED          16
#define P_RECORD        17
#define P_GPIO_0        20
#define P_GPIO_1        21

unsigned char Parameter_Number = 0;

/* CODE */
#define MSF_CODE_N              	'n' // NO CODE
#define MSF_CODE_PARAMETER         	'p' // 
#define MSF_CODE_PRINT             	'u' // 

#define MSF_CODE_THRESHOLD         	't'
#define MSF_CODE_GPIO              	'g'
#define MSF_CODE_FORMAT            	'f'

#define MSF_CODE_EEPROM_ADDRESS    	'a'
#define MSF_CODE_EEPROM_VALUE      	'v'

#define MSF_CODE_TIME_ALL          	'a'
#define MSF_CODE_TIME_SECONDS      	's'
#define MSF_CODE_TIME_MINUTES      	'm'
#define MSF_CODE_TIME_HOURS        	'h'

#define MSF_CODE_CALENDAR_ALL      	'a'
#define MSF_CODE_CALENDAR_WDAY     	'w'
#define MSF_CODE_CALENDAR_DAY      	'd'
#define MSF_CODE_CALENDAR_MONTH    	'm'
#define MSF_CODE_CALENDAR_YEAR     	'y'

#define MSF_CODE_ANALOG_REF        	'r' // In V1 not supported

#define MSF_CODE_ID                	'1'
#define MSF_CODE_SWv               	'2'
#define MSF_CODE_HWv               	'3'
#define MSF_CODE_SPv               	'4'
#define MSF_CODE_RESET             	'!'
#define MSF_CODE_DEBUG             	'd'
#define MSF_CODE_RESET_FTY_DEF     	'r' // Set Factory defaults

#define MSF_CODE_TLOO              	'l'	// Text Location On OLED

#define MSF_CODE_CLEAR             	'c'

#define MSF_CODE_MODE              	'm' // Data Logger
#define MSF_CODE_DATA              	'd' // Data Logger
#define MSF_CODE_0                 	'0'
#define MSF_CODE_1                 	'1'

#define MSF_CODE_CNT               	'x'
#define MSF_CODE_GET               	'g'

/* ANSWER */
/* MS -> HOST Sends Answer -> "#.A.N.n:ANSWER\r\n" */

#define MSF_N                      	0x00
#define MSF_ACK                    	'A'		// Commands is Akcepted
#define MSF_NACK                   	'N'		// Commands is not Akcepted
#define MSF_CANCEL                 	'C'		// MSF RX Buffer Overfow
//.............

/* FORMAT */
#define UART_FORMAT_1               '0'
#define UART_FORMAT_2               '1'
#define UART_FORMAT_3               '2'

/*
 * for TEMPERATURE  -> '1' = [CELSIUM]
 *                  -> '2' = [FAHRENHEIT]
 * .............................................
 * for TIME         -> '1' = [ 0-24 ]	
 *                  -> '2' = [ AM/PM ]	// In V1 not supported
 * .............................................
 * for PRESSURE     -> '1' = [ PASCALS ]
 *                  -> '2' = [ mmHg ]
 * .............................................
//..............................................................................

typedef struct{

    BYTE    START_Char;        	// '#'
    BYTE    _0;					// Seperator -> '.'
    BYTE    CMD;
    BYTE    _1;					// Seperator -> '.'
    BYTE    VAR;
    BYTE    _2;					// Seperator -> '.'
    BYTE    CODE;
    BYTE    _3;					// Seperator -> ':'
    BYTE   VALUE[MSF_BUFFER_SIZE-8];

}tMSF_RX_DATA;

unsigned char MSF_TX_Buffer_cnt = 0;
unsigned char MSF_RX_Buffer_cnt = 0;

unsigned char MSF_TX_Buffer[UART_BUFFER_SIZE] = {0};
unsigned char MSF_RX_Buffer[UART_BUFFER_SIZE] = {0};

unsigned char MSF_RX_Complete = 0;
unsigned char MSF_TX_CRC_byte = 0;

//..............................................................................
unsigned char UART_RX_ERROR = 0;
/*
 * UART_RX_ERROR:
 * VALUE:
 * 0 -> Ok
 * 1 -> MSF_RX_Buffer Overflov
 *
*/
//..............................................................................
struct{

        unsigned char version;                                                  // Vai ?is parametre (sensors) ir ?aj? versij?
        unsigned char uart  ;                                                   // Vai datus izvad?t uz UART
        unsigned char gpio_mode ;                                               // Vai p?c ?i parametra raust?t GPIO
        unsigned char format ;                                                  // Parametra izvdaes formats -> mmHG vai kPa
        unsigned int  threshold;                                                // Veriba pie kuras nostrada GPIO
        unsigned char oled;                                                     // Vai izvadit uz OLED displeja
        unsigned char tloo;                                                     // Parametra vertibas izvades pozicija uz OLED

}Ch_X_STATE[EE_PARAMETER_CNT];



#endif //MSF_SERIAL_V1_0_h