# AVR_GPIO_DRIVER
GPIO Ports and Registers in AVR ATmega16/ATmega32 Driver 

## Driver description
Our driver has five main functions:

1- void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)


 Description :

 - Setup the direction of the required pin input/output.
 - If the input port number or pin number are not correct, The function will not handle the request.
 

2- void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)


  Description :
  
  - Write the value Logic High or Logic Low on the required pin.
  - If the input port number or pin number are not correct, The function will not handle the request.
  - If the pin is input, this function will enable/disable the internal pull-up resistor.


3- uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)


  Description :
  
  - Read and return the value for the required pin, it should be Logic High or Logic Low.
  - If the input port number or pin number are not correct, The function will return Logic Low.


4- void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)


  Description :
  
  - Setup the direction of the required port all pins input/output.
  - If the direction value is PORT_INPUT all pins in this port should be input pins.
  - If the direction value is PORT_OUTPUT all pins in this port should be output pins.
  - If the input port number is not correct, The function will not handle the request.


5- void GPIO_writePort(uint8 port_num, uint8 value)


  Description :
  
  - Write the value on the required port.
  - If any pin in the port is output pin the value will be written.
  - If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
  - If the input port number is not correct, The function will not handle the request.
 

6- uint8 GPIO_readPort(uint8 port_num)


  Description :
  
  - Read and return the value of the required port.
  - If the input port number is not correct, The function will return ZERO value.

