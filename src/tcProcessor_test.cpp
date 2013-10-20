/******************************************************************************
 *
 * @file tcProcessor_test.cpp
 *
 * @version Sep 25, 2013
 *
 * @author Brian M. Craig
 *
 ******************************************************************************/

#include <gmock/gmock.h>			// include gmock and gtest
#include <gtest/gtest.h>
#include "tcInterface_mock.h"

#include "tcProcessor.h"

using ::testing::Return;

/**
 * @brief This is good test case the message should be sent
 */
TEST(tcProcessor,SendMessage_Good)
{
	tcInterface_mock lcInterface;
	tcProcessor      lcProcessor( lcInterface );

	std::string lcString( "Hello World!" );

	EXPECT_CALL( lcInterface, Open() )	// expect call to tcInterface::Open
		.Times(1)						// the number of calls to expect
		.WillOnce(Return(true));		// specify the return value

	EXPECT_CALL( lcInterface, Send( lcString.c_str(), lcString.size() ) )
		.Times(1);						// expect 1 call to tcInterface::Send

	EXPECT_CALL( lcInterface, Close())	// expect 1 call to tcInterface::Close
		.Times(1);

	// expect the call to return true
	EXPECT_TRUE( lcProcessor.SendMessage( lcString ) );
};

/**
 * @brief This is bad test case the message should not be sent
 */
TEST(tcProcessor,SendMessage_Bad)
{
	tcInterface_mock lcInterface;
	tcProcessor      lcProcessor( lcInterface );

	std::string lcString( "Hello World!" );

	EXPECT_CALL( lcInterface, Open() )	// expect call to tcInterface::Open
		.Times(1)						// the number of calls to expect
		.WillOnce(Return(false));		// specify the return value

	EXPECT_CALL( lcInterface, Send( lcString.c_str(), lcString.size() ) )
		.Times(0);						// expect no call to tcInterface::Send

	EXPECT_CALL( lcInterface, Close() )	// expect no call to tcInterface::Close
		.Times(0);

	// expect the call to return false
	EXPECT_FALSE( lcProcessor.SendMessage( lcString ) );
};

/**
 * @brief This is a test case for the status method
 */
TEST(tcProcessor,Status_Good)
{
	tcInterface_mock lcInterface;
	tcProcessor      lcProcessor( lcInterface );

	EXPECT_CALL( lcInterface, Status() )	// anytime Status() is called, it
		.WillRepeatedly( Return(true) );	// returns true

	// expect the call to return true
	EXPECT_TRUE( lcProcessor.CheckInterface() );
};


/**
 * @brief This is a test case for the status method, when the interface status
 *        is bad
 */
TEST(tcProcessor,Status_Bad)
{
	tcInterface_mock lcInterface;
	tcProcessor      lcProcessor( lcInterface );

	ON_CALL( lcInterface, Status() )		// anytime Status() is called, it
		.WillByDefault( Return(false) );	// returns false, but this is not
											// tested - warning will be
											// generated, but test will pass

	// expect the call to return false
	EXPECT_FALSE( lcProcessor.CheckInterface() );
};
