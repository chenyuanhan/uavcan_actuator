

#include "canard.h"
#include "canard_stm32.h"
#include "stm32f1xx_hal.h"
#include "main.h"


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define APP_VERSION_MAJOR                                           99
#define APP_VERSION_MINOR                                           99
#define APP_NODE_NAME                                               "skyyu.uavcan_actuator"
#define GIT_HASH                                                    0xBADC0FFE

#define UAVCAN_GET_NODE_INFO_DATA_TYPE_SIGNATURE                    0xee468a8121c46a9e
#define UAVCAN_GET_NODE_INFO_DATA_TYPE_ID                           1
#define UAVCAN_GET_NODE_INFO_RESPONSE_MAX_SIZE                      ((3015 + 7) / 8)

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_ID                          1030
#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_SIGNATURE                   0x217f5c87d7ec951d
#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_MAX_VALUE                   8192

#define UNIQUE_ID_LENGTH_BYTES                                      16

#define UAVCAN_NODE_HEALTH_OK                                       0
#define UAVCAN_NODE_HEALTH_WARNING                                  1
#define UAVCAN_NODE_HEALTH_ERROR                                    2
#define UAVCAN_NODE_HEALTH_CRITICAL                                 3

#define UAVCAN_NODE_MODE_OPERATIONAL                                0
#define UAVCAN_NODE_MODE_INITIALIZATION                             1

#define UAVCAN_NODE_STATUS_MESSAGE_SIZE                             7

#define UAVCAN_NODE_STATUS_MESSAGE_SIZE                             7
#define UAVCAN_NODE_STATUS_DATA_TYPE_ID                             341
#define UAVCAN_NODE_STATUS_DATA_TYPE_SIGNATURE                      0x0f0868d0c1a7c6f1

#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_ID                           16370   
#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_SIGNATURE                    0xe02f25d6e0c98ae0     
#define UAVCAN_PROTOCOL_DEBUG_KEYVALUE_MESSAGE_SIZE                 62                   
#define UNIQUE_ID_LENGTH_BYTES                                      16

#define UAVCAN_PROTOCOL_PARAM_GETSET_ID                             11
#define UAVCAN_PROTOCOL_PARAM_GETSET_SIGNATURE                      0xa7b622f939d1a4d5    


extern UART_HandleTypeDef huart1;

typedef struct
{
  uint8_t* name;
  int64_t val; 
  int64_t min;
  int64_t max;
  int64_t defval;
} param_t;


bool signalTag(uint16_t transfer);

void showRcpwmonUart(void);

void sendCanard(void);

void receiveCanard(void);

void spinCanard(void);

void publishCanard(void);

void showRcpwmonUart(void);

void ledStatus(void);

void parametersLoad(void);

void parametersSave(void);

void led(void);

void rawcmdHandleCanard(CanardRxTransfer* transfer);

void getsetHandleCanard(CanardRxTransfer* transfer);

void getNodeInfoHandleCanard(CanardRxTransfer* transfer);

void pwmUpdate(uint16_t canVaule);

void parameterCheck(void);


uint16_t makeNodeInfoMessage(uint8_t buffer[UAVCAN_GET_NODE_INFO_RESPONSE_MAX_SIZE]);




