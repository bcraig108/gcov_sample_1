/*
 * tcInterface_mock.h
 *
 *  Created on: Oct 18, 2013
 *      Author: Dad
 */

#ifndef TCINTERFACE_MOCK_H_
#define TCINTERFACE_MOCK_H_

#include <gmock/gmock.h>
#include "tcInterface.h"

/**
 * @brief This is the mock of the interface class
 */
class tcInterface_mock : public tcInterface {
public:

	// general format for mocks is MOCK_METHODn, where n is the number of args
	MOCK_METHOD0(Open, bool());		// no args, returns bool
	MOCK_METHOD0(Close, void());	// no args, returns void

	// the send method has 2 args and returns void
	MOCK_METHOD2(Send, void( const void* apvData, unsigned anSize ));

	// Status method is const - use MOCK_CONST_METHODn
	MOCK_CONST_METHOD0(Status, bool());
};

#endif /* TCINTERFACE_MOCK_H_ */
