#-------------------------------------------------------------------- 
 Project Name		: MDP - Microprocessor Development Project
 Project Code		: ET1035
 Filename			: Makefile
 Purpose			: ADC and GPIO interface
 Description		: control led through ADC
 Author(s)			: Sharthak Raj
#--------------------------------------------------------------------    
#See LICENSE for license details.
 
#+++++++++++++++++++++++
# Configurations        
#+++++++++++++++++++++++
# Include the BSP settings

CONFIG_PATH=~/.config/vega-tools/settings.mk
ifeq ("$(wildcard $(CONFIG_PATH))","")
$(error Please install [VEGA SDK]/[VEGA Tools] and setup the environment)
endif

include $(CONFIG_PATH)

ifeq ("$(wildcard $(VEGA_TOOLCHAIN_PATH))","")
$(error Please install [VEGA Tools] and setup the environment)
endif

ifeq ("$(wildcard $(VEGA_SDK))","")
$(error Please install [VEGA SDK] and setup the environment)
endif
SDK_PATH=${VEGA_SDK}

#+++++++++++++++++++++++
# Executable name
#+++++++++++++++++++++++
EXECUTABLE_NAME=UART_ADC_Led_GPIO


include $(SDK_PATH)/bsp/common/config.mk
	
