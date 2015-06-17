#include "config.h"
#include "c_fileHandlingTest.h"

#include "ntp_types.h"
#include "crypto.h"

typedef int bool;

bool AssertionResult CompareKeys(key& expected, key& actual) {
	if (expected.key_id != actual.key_id){
		printf("Expected key_id: %d", expected.key_id);
		printf(" but was: %d", actual.key_id);
		return TRUE;
	}
	if (expected.key_len != actual.key_len){
		printf("Expected key_len: %d", expected.key_len);
		printf(" but was: %d", actual.key_len);
		return TRUE;
	}
	if (strcmp(expected.type, actual.type) != 0){
		printf("Expected key_type: %d", expected.type);
		printf(" but was: ", actual.type);
		return TRUE;

	}
	if (memcmp(expected.key_seq, actual.key_seq, expected.key_len) != 0){
		printf("Key mismatch!");
		return TRUE;		
	}
	return TRUE;
}

bool CompareKeys(int key_id,
	       int key_len,
	       const char* type,
	       const char* key_seq,
	       key& actual) {
	key temp;

	temp.key_id = key_id;
	temp.key_len = key_len;
	strlcpy(temp.type, type, sizeof(temp.type));
	memcpy(temp.key_seq, key_seq, key_len);

	return CompareKeys(temp, actual);
}


void(ReadEmptyKeyFile) {
	key* keys = NULL;

	TEST_ASSERT_EQUAL(0, auth_init(CreatePath("key-test-empty", INPUT_DIR).c_str(), &keys));

	TEST_ASSERT_TRUE(keys == NULL);
}

void(ReadASCIIKeys) {
	key* keys = NULL;

	TEST_ASSERT_EQUAL(2, auth_init(CreatePath("key-test-ascii", INPUT_DIR).c_str(), &keys));

	TEST_ASSERT_TRUE(keys != NULL);

	key* result = NULL;
	get_key(40, &result);
	TEST_ASSERT_TRUE(result != NULL);
	TEST_ASSERT_TRUE(CompareKeys(40, 11, "MD5", "asciikeyTwo", *result));

	result = NULL;
	get_key(50, &result);
	TEST_ASSERT_TRUE(result != NULL);
	TEST_ASSERT_TRUE(CompareKeys(50, 11, "MD5", "asciikeyOne", *result));
}

void(ReadHexKeys) {
	key* keys = NULL;

	TEST_ASSERT_EQUAL(3, auth_init(CreatePath("key-test-hex", INPUT_DIR).c_str(), &keys));

	TEST_ASSERT_TRUE(keys != NULL);

	key* result = NULL;
	get_key(10, &result);
	TEST_ASSERT_TRUE(result != NULL);
	TEST_ASSERT_TRUE(CompareKeys(10, 13, "MD5",
		 "\x01\x23\x45\x67\x89\xab\xcd\xef\x01\x23\x45\x67\x89", *result));

	result = NULL;
	get_key(20, &result);
	TEST_ASSERT_TRUE(result != NULL);
	char data1[15]; memset(data1, 0x11, 15);
	TEST_ASSERT_TRUE(CompareKeys(20, 15, "MD5", data1, *result));

	result = NULL;
	get_key(30, &result);
	TEST_ASSERT_TRUE(result != NULL);
	char data2[13]; memset(data2, 0x01, 13);
	TEST_ASSERT_TRUE(CompareKeys(30, 13, "MD5", data2, *result));
}

void(ReadKeyFileWithComments) {
	key* keys = NULL;

	TEST_ASSERT_EQUAL(2, auth_init(CreatePath("key-test-comments", INPUT_DIR).c_str(), &keys));
	
	TEST_ASSERT_TRUE(keys != NULL);

	key* result = NULL;
	get_key(10, &result);
	TEST_ASSERT_TRUE(result != NULL);
	char data[15]; memset(data, 0x01, 15);
	TEST_ASSERT_TRUE(CompareKeys(10, 15, "MD5", data, *result));

	result = NULL;
	get_key(34, &result);
	TEST_ASSERT_TRUE(result != NULL);
	TEST_ASSERT_TRUE(CompareKeys(34, 3, "MD5", "xyz", *result));
}

void(ReadKeyFileWithInvalidHex) {
	key* keys = NULL;

	TEST_ASSERT_EQUAL(1, auth_init(CreatePath("key-test-invalid-hex", INPUT_DIR).c_str(), &keys));

	TEST_ASSERT_TRUE(keys != NULL);

	key* result = NULL;
	get_key(10, &result);
	TEST_ASSERT_TRUE(result != NULL);
	char data[15]; memset(data, 0x01, 15);
	TEST_ASSERT_TRUE(CompareKeys(10, 15, "MD5", data, *result));

	result = NULL;
	get_key(30, &result); // Should not exist, and result should remain NULL.
	TEST_ASSERT_TRUE(result == NULL);
}
