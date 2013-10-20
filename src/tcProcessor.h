/*
 * tcProcessor.h
 *
 *  Created on: Oct 18, 2013
 *      Author: Dad
 */

#ifndef TCPROCESSOR_H_
#define TCPROCESSOR_H_

#include "tcInterface.h"
#include <string>

/**
 * @brief This is the class under test, which interacts with the interface class
 */
class tcProcessor {
public:

	tcProcessor( tcInterface& arcInterface );

	~tcProcessor( void );

	bool SendMessage( std::string& arcMessage );

	bool CheckInterface( void );

protected:

	tcInterface& mrcInterface;
};

#endif /* TCPROCESSOR_H_ */
