/**
 * Unit Tests for the class
 **/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
protected:
	GuesserTest() {}		   // constructor runs before each test
	virtual ~GuesserTest() {}  // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

// Test if guess is empty
TEST(GuesserTest, empty_guess)
{
	Guesser object("Secret");
	int expected_distance = 6; // Length of "Secret"
	ASSERT_EQ(object, expected_distance);
}

// Test if guess is same as secret
TEST(GuesserTest, same_guess)
{
	Guesser object("Secret");
	int expected_distance = 0; // No difference
	ASSERT_EQ(object.match("Secret"), expected_distance);
}

// Test if guess is same as secret with different case
TEST(GuesserTest, same_guess_different_case)
{
	Guesser object("Secret");
	int expected_distance = 0; // Assuming case-insensitive comparison
	ASSERT_EQ(object.match("sECRET"), expected_distance);
}

// Test if guess is same as secret with different length
TEST(GuesserTest, same_guess_different_length)
{
	Guesser object("Secret");
	int expected_distance = 1; // One extra character
	ASSERT_EQ(object.match("Secrett"), expected_distance);
}

// Test if zero remaining guesses but the guess is the same as secret
TEST(GuesserTest, zero_remaining_same_guess)
{
	Guesser object("Secret");
	int expected_distance = 0; // No difference
	ASSERT_EQ(object.remaining(), expected_distance);

	int expected_remaining = 0; // Assuming no guesses remaining
	ASSERT_EQ(object.remaining(), expected_remaining);
}

// Test if guess is 32 characters long
TEST(GuesserTest, long_guess)
{
	Guesser object("Secrettttttttttttttttttttttttttt");
	ASSERT_EQ(object.remaining(), 26); // Length of "Secret" is 6, so 32 - 6 = 26
	ASSERT_FALSE(object.match("Bad"));
}
