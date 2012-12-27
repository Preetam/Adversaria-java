#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#ifndef ADVERSARIA_H
#define ADVERSARIA_H

#define HEADER_SIZE 16 // 16 byte header
#define MAX_ROWS 5

typedef struct {
	uint32_t timestamp;
	float in;
	float out;
} row;

void writeHeader(FILE *p);
void writeFloatToFile(FILE *fp, int nth, float val);
float readFloatFromFile(FILE *fp, int nth);
void writeRowToFile(FILE *fp, int location, row r);
row readRowFromFile(FILE *fp, int location);
void printRow(row r);
void printData(FILE *fp);

#endif
