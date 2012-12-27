#include "adversaria.h"

int main(void) {
	FILE *fp = fopen("db.advs", "w+");
	writeHeader(fp);
	int i;

	for(i = 0; i < MAX_ROWS; i++) {
		row r = {time(0)+i, ((float) i), ((float) rand() / (RAND_MAX))*20};
		writeRowToFile(fp, i, r);
	}

	fclose(fp);
	
	fp = fopen("db.advs", "rb");

	printData(fp);
	fclose(fp);

	return EXIT_SUCCESS;
}

void writeHeader(FILE *fp) {
	char *header = "ADVS";
	fprintf(fp, "%s", header);
}

void writeRowToFile(FILE *fp, int location, row r) {
	char inBuffer[4] = {0};
	char outBuffer[4] = {0};
	fseek(fp, location*12+HEADER_SIZE, SEEK_SET);
	memcpy(inBuffer, &(r.in), 4);
	memcpy(outBuffer, &(r.out), 4);
	fwrite(&(r.timestamp), 4, 1, fp);
	fwrite(inBuffer, 4, 1, fp);
	fwrite(outBuffer, 4, 1, fp);
}

row readRowFromFile(FILE *fp, int location) {
	char inBuffer[4] = {0};
	char outBuffer[4] = {0};
	uint32_t timestamp = 0;

	fseek(fp, 12*location+HEADER_SIZE, SEEK_SET);
	fread(&timestamp, 4, 1, fp);
	fread(inBuffer, 4, 1, fp);
	fread(outBuffer, 4, 1, fp);

	float in = 0;
	float out = 0;
	memcpy(&in, inBuffer, 4);
	memcpy(&out, outBuffer, 4);

	row r = {timestamp, in, out};
	return r;
};

void printRow(row r) {
	printf("[ %d, %f, %f ]\n", r.timestamp, r.in, r.out);
}

void printData(FILE *fp) {
	int i;
	printf("[");
	for(i = 0; i < MAX_ROWS; i++) {
		row r = readRowFromFile(fp, i);
		printf("[%d, %f, %f]", r.timestamp, r.in, r.out);
		if(i != MAX_ROWS)
			printf(",");
	}
	printf("]");
}

void writeFloatToFile(FILE *fp, int nth, float val) {
	char buffer[4] = {0};
	fseek(fp, nth*4, 4);
	memcpy(buffer, &val, 4);
	fwrite(buffer, 4, 1, fp);
}

float readFloatFromFile(FILE *fp, int nth) {
	char buffer[4] = {0};
	fseek(fp, 4*nth+8, SEEK_SET);
	fread(buffer, 4, 1, fp);

	float inFile = 0;
	memcpy(&inFile, buffer, 4);
	return inFile;
}
