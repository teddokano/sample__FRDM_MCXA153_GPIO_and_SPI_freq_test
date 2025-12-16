# sample__FRDM_MCXA153_GPIO_and_SPI_freq_test

## What is this? 

One day, an old mate asked me,  
"Is there a microcontroller that can run SPI at 25MHz or toggle GPIO at 40MHz?"  
Well, I figured out from the datasheet that the MCX-A153 might do the job, but I properly tested it out ;) 

These are ample code projects for testing FRDM-MCXA153 GPIO toggle speed and SPI maximum frequency. It runs on MCUXpresso with [FRDM-MCXA153](https://www.nxp.com/design/design-center/development-boards-and-designs/FRDM-MCXA153). 

## Contents

This repository is distributed as a snapshot of MCUXpresso IDE workspace containing 3 projects. 

### SPI_SCLK_freq_check_FRDM_MCXA153
SPI operation sample with SPI clock frequency of 25MHz. The setting of clock frequency is done using `r01lib` class driver API.   

```cpp
#include	"r01lib.h"

SPI			spi( D11, D12, D13, D10 );	//	MOSI, MISO, SCLK, CS

int main( void )
{
	spi.frequency( 25'000'000 );
	spi.mode( 0 );
```

### SPI_SCLK_freq_check_FRDM_MCXA153
GPIO tggling speed test sample.  
This sample shows a blue LED on the board toggles in visible spee.   
And D0 pin at Arduino-socket toggles in maximum speed of the microcontroller. 

The LED and D0 are configured as output pins before toggling.  
The LED pin is controlled by class driver API.  
The D0 pin is controlled by MCUXpresso SDK's API (difinitions of register address/struct) to achieve direct hardware access.  

D0 pin toggle is unrolled to reduce overhead of its loop. 

```cpp
#include	"r01lib.h"

DigitalOut	led( BLUE );
DigitalOut	pinout( D0 );	//	D0 == P1_4 (bit_4 on GPIO_1)

#define	PORT_BASE		GPIO1_BASE
#define	BIT_ON_PORT		4

constexpr uint32_t	bitflag	= 1 << BIT_ON_PORT;	//	

int main( void )
{
	...
	
	while ( true )
	{
		led	= !led;

		for ( uint32_t i = 0; i < 1'000'000UL; i++ )
		{
			/*	following 2 lines are equivalent to next 2 lines
			 *		pinout	= false;		
			 *		pinout	= true;
			 */
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			
			/*	10 times unrolled loop  */
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PCOR	= bitflag;
			((GPIO_Type *)PORT_BASE)->PSOR	= bitflag;
		}
	}
}
```

## How to use this? 

A guide video (Japanese) is on [YouTube shorts](https://youtube.com/shorts/-8h3eZVqEoM).   

[<img src="https://github.com/teddokano/additional_files/blob/main/sample__FRDM_MCXA153_GPIO_and_SPI_freq_test/shorts.PNG" width="30%">](https://youtube.com/shorts/-8h3eZVqEoM).   

