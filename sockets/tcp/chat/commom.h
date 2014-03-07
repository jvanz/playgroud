/*
 * =====================================================================================
 *
 *       Filename:  commom.h
 *
 *    Description: Common structure in both server and client side.
 *
 *        Version:  1.0
 *        Created:  02/27/2014 08:37:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José Guilherme Vanz (vanz), guilherme.sft@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */


#ifndef COMMOM_HEADER
#define COMMOM_HEADER

#define MSG_TEXT_SIZE 100
#define READ_BLOCK_SIZE 256


#include <stdlib.h>

/* *
 * message type is used to send a message between server and client side.
 * Its fields:
 * 	length : size_t field that contains the size of the message
 * 	msg : char pointer that constains the message
 * */
typedef struct {
	size_t length;
	char msg[MSG_TEXT_SIZE];
} message;

size_t message_byte_size(const message * msg);
message* create_message(const char* msg_text);

#endif
