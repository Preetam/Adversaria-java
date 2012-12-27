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
	char buffer[ROW_SIZE] = {0};
	fseek(fp, location*ROW_SIZE+HEADER_SIZE, SEEK_SET);
	memcpy(buffer, &r, ROW_SIZE);
	fwrite(buffer, ROW_SIZE, 1, fp);
}

row readRowFromFile(FILE *fp, int location) {
	row r;
	char buffer[ROW_SIZE] = {0};
	fseek(fp, ROW_SIZE*location+HEADER_SIZE, SEEK_SET);
	fread(buffer, ROW_SIZE, 1, fp);
	memcpy(&r, buffer, sizeof(r));
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
		if(i < MAX_ROWS-1)
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
