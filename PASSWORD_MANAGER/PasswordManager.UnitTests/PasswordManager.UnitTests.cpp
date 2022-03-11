#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "Application.h"
#include "Node.h"
#include "LinkedList.h"
#include "Encryption.h"
#include "PasswordManager.h"
}

namespace PasswordManagerUnitTests
{
	TEST_CLASS(ApplicationUnitTests)
	{
	public:
		TEST_METHOD(T001_checkPasswordStrength_noInput_0)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case test function checkPasswordStrength() should return 0 (as the empty string was passed)
			Assert::AreEqual(0, checkPasswordStrength(""));
		}
		TEST_METHOD(T002_checkPasswordStrength_allNumbersLength4_2)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this test case function checkPasswordStrength() should return 2 (as there are only numbers used and length is smaller than 8)
			Assert::AreEqual(2, checkPasswordStrength("0123"));
		}
		TEST_METHOD(T003_checkPasswordStrength_allUppercaseLength10_3)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 3 (as there are only uppercase letters used and length is larger than 8 but smaller than 12)
			Assert::AreEqual(3, checkPasswordStrength("SOMEPASSWD"));
		}
		TEST_METHOD(T004_checkPasswordStrength_allLowercaseLength12_4)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 4 (as there are only lowercase letters used and length is larger than 12)
			Assert::AreEqual(4, checkPasswordStrength("SOMEPASSWORD"));
		}
		TEST_METHOD(T005_checkPasswordStrength_lowercaseAndSpecialsLength10_5)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 5 (as there are lowercase letters and special symbols used and length is larger than 8 but smaller than 12)
			Assert::AreEqual(5, checkPasswordStrength("_some_p@ss"));
		}
		TEST_METHOD(T006_checkPasswordStrength_lowercaseAndNumbersLength12_6)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 6 (as there are lowercase letters and numbers used and length is 12 characters)
			Assert::AreEqual(6, checkPasswordStrength("1efg0klk4fgj"));
		}
		TEST_METHOD(T007_checkPasswordStrength_lowercaseUppercaseAndSpecialsLength10_7)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 7 (as there are only lowercase letters and special symbols used and length is larger than 8 but smaller than 12)
			Assert::AreEqual(7, checkPasswordStrength("_SoMe_p@sS"));
		}
		TEST_METHOD(T008_checkPasswordStrength_lowercaseUppercaseAndSpecialsLength12_8)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 8 (as there are lowercase, uppercase letters and special symbols used and length is equal 12)
			Assert::AreEqual(8, checkPasswordStrength("_SoMe_p@sSWd"));
		}
		TEST_METHOD(T009_checkPasswordStrength_allTypesLength12_9)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 9 (as there are all types of characters (numbers, uppercase letters, lowercase letters, special characters (but only 2) used and length 12 characters)
			Assert::AreEqual(9, checkPasswordStrength("aG%3f&k75HRH"));
		}
		TEST_METHOD(T010_checkPasswordStrength_allTypesLength15_10)
		{
			// As it is described in checkPasswordStrength() description, function rates a passed password on scale from 0 to 10, for every type of character 2 points are given, and 2 pts are given for length >= 12
			// In this case function checkPasswordStrength() should return 10 (as there are all types of characters (numbers, uppercase letters, lowercase letters, special characters) used and length is more than 12 characters)
			Assert::AreEqual(10, checkPasswordStrength("aG%3f&k75HgR_g^"));
		}

		TEST_METHOD(T011_checkPasswordStrength_generatePassword_moreThan7) {
			// In this test case it is tested that generatePassword() returns a password which has a strength score more than 6
			Assert::IsTrue(checkPasswordStrength(generatePassword()) >= 7);
		}
		TEST_METHOD(T012_checkPasswordStrength_generatePassword_moreThan7) {
			// In this test case it is tested that generatePassword() returns a password which has a strength score more than 6
			Assert::IsTrue(checkPasswordStrength(generatePassword()) >= 7);
		}
		TEST_METHOD(T013_checkPasswordStrength_generatePassword_moreThan7) {
			// In this test case it is tested that generatePassword() returns a password which has a strength score more than 6
			Assert::IsTrue(checkPasswordStrength(generatePassword()) >= 7);
		}
		TEST_METHOD(T014_checkPasswordStrength_generatePassword_moreThan7) {
			// In this test case it is tested that generatePassword() returns a password which has a strength score more than 6
			Assert::IsTrue(checkPasswordStrength(generatePassword()) >= 7);
		}
		TEST_METHOD(T015_checkPasswordStrength_generatePassword_moreThan7) {
			// In this test case it is tested that generatePassword() returns a password which has a strength score more than 6
			Assert::IsTrue(checkPasswordStrength(generatePassword()) >= 7);
		}

		TEST_METHOD(T016_initApplication_appname_username_password_appname) {
			// In this test case it is tested that initApplication() saves value of appName to pApplication structure properly
			pApplication app = initApplication("appname", "username", "password");
			Assert::AreEqual("appname", app->appName);
		}
		TEST_METHOD(T017_initApplication_appname_someUsername_password_appname) {
			// In this test case it is tested that initApplication() saves value of username to pApplication structure properly
			pApplication app = initApplication("appname", "someUsername", "password");
			Assert::AreEqual("someUsername", app->username);
		}
		TEST_METHOD(T018_initApplication_appname_someUsername_somePassword_appname) {
			// In this test case it is tested that initApplication() saves value of username to pApplication structure properly
			pApplication app = initApplication("appname", "someUsername", "somePassword");
			Assert::AreEqual("somePassword", app->password);
		}
	};
	TEST_CLASS(NodeUnitTests) {
	public:
		TEST_METHOD(T001_initNode_appname_username_password_appname) {
			// In this test case it is tested that initNode() saves value of appName to pApplication structure in pNode properly
			pNode node = initNode("appname", "username", "password");
			Assert::AreEqual("appname", node->data->appName);
		}
		TEST_METHOD(T002_initNode_appname_someUsername_password_someUsername) {
			// In this test case it is tested that initNode() saves value of username to pApplication structure in pNode properly
			pNode node = initNode("appname", "someUsername", "password");
			Assert::AreEqual("someUsername", node->data->username);
		}
		TEST_METHOD(T003_initNode_appname_someUsername_somePassword_somePassword) {
			// In this test case it is tested that initNode() saves value of username to pApplication structure in pNode properly
			pNode node = initNode("appname", "someUsername", "somePassword");
			Assert::AreEqual("somePassword", node->data->password);
		}

		TEST_METHOD(T004_linkNext_appname_username_password_appname) {
			// In this test case it is tested that linkNext() links two pNodes properly and values can be retracted with a call to .next
			pNode n = createNode();
			pNode node = initNode("appname", "username", "password");
			linkNext(n, node);
			Assert::AreEqual("appname", n->next->data->appName);
		}
		TEST_METHOD(T005_linkNext_appname_someUsername_password_someUsername) {
			// In this test case it is tested that linkNext() links two pNodes properly and values can be retracted with a call to .next
			pNode n = createNode();
			pNode node = initNode("appname", "someUsername", "password");
			linkNext(n, node);
			Assert::AreEqual("someUsername", n->next->data->username);
		}
		TEST_METHOD(T006_linkNext_appname_someUsername_somePassword_somePassword) {
			// In this test case it is tested that linkNext() links two pNodes properly and values can be retracted with a call to .next
			pNode n = createNode();
			pNode node = initNode("appname", "someUsername", "somePassword");
			linkNext(n, node);
			Assert::AreEqual("somePassword", n->next->data->password);
		}
	};
}
