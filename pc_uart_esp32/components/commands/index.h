#ifndef _COMMAND_INDEX_H_
#define _COMMAND_INDEX_H_

#define CMD_CMD_SIZE 	4 	// size of command part and seperator
#define CMD_ARG_SIZE	128 // size of argument part
#define CMD_TOTAL_SIZE 	CMD_CMD_SIZE + CMD_ARG_SIZE
#define CMD_MEMORY_SIZE CMD_TOTAL_SIZE * sizeof(char)

// Index of commands
#define CMD_PING 		0
#define CMD_STATUS  	1
#define CMD_STATUS_LED 	2

#define CMD_CLOCK 		10

#define CMD_WRITE		30


#endif
