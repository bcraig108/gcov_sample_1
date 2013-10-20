/*
 * tcProcessor.cpp
 *
 *  Created on: Oct 18, 2013
 *      Author: Dad
 */

#include "tcProcessor.h"

tcProcessor::tcProcessor( tcInterface& arcInterface ) :
	mrcInterface( arcInterface ) {};

tcProcessor::~tcProcessor( void ) {};

bool tcProcessor::SendMessage( std::string& arcMessage ) {
	if ( mrcInterface.Open() ) {
		mrcInterface.Send( arcMessage.c_str(), arcMessage.size() );
		mrcInterface.Close();
		return true;
	}
	else
	{
		return false;
	}
}

bool tcProcessor::CheckInterface( void ) {
	return mrcInterface.Status();
}
