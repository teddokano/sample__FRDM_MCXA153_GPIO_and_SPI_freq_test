/** test code for r01lib
 *
 *  @author Tedd OKANO
 *
 *  Released under the MIT license
 */

#include	"r01lib.h"

DigitalOut	led( BLUE );
DigitalOut	pinout( D0 );	//	D0 == P1_4 (bit_4 on GPIO_1)

#define	PORT_BASE		GPIO1_BASE
#define	BIT_ON_PORT		4

constexpr uint32_t	bitflag	= 1 << BIT_ON_PORT;	//	

int main( void )
{
	led		= true;
	pinout	= true;

	printf( "GPIO operation sample code\r\n" );
	printf( "D0 pin on Arduino-shield socket toggles in maximum speed\r\n" );
	printf( "(The maximum speed is achieved by direct hardware access)\r\n" );
	printf( "A blue color LED toggles in visible speed\r\n" );
	
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
