/*
 * tcInterface.h
 *
 *  Created on: Oct 18, 2013
 *      Author: Dad
 */

#ifndef TCINTERFACE_H_
#define TCINTERFACE_H_

/**
 * @brief This is the class that will be mocked
 */
class tcInterface {
public:
	tcInterface( void ) {};
	virtual ~tcInterface( void ) {};
	virtual bool Open( void ) = 0;
	virtual void Close( void ) = 0;
	virtual void Send( const void* apvData, unsigned anSize ) = 0;
	virtual bool Status( void ) const = 0;
};

#endif /* TCINTERFACE_H_ */
