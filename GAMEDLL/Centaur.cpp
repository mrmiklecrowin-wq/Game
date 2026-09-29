#include "Centaur.h"



double Centaur::Result_Math_Centaur(double& Range) {

	double Result_Time_Centaur = 0;


	double Speed = 15;
	double Travel_Time = 8;
	double Stop_First = 2;
	double Stop_Next = 2;



	double block_distance = Speed * Travel_Time;
	int full_blocks = static_cast<int>(Range / block_distance);
	double remainder = Range - full_blocks * block_distance;


	double movement_time = Range / Speed;

	int num_rests = 0;
	if (remainder > 0) {
		num_rests = full_blocks;
	}
	else {
		num_rests = full_blocks - 1;
	}

	double rest_time = 0;
	if (num_rests > 0) {
		rest_time = Stop_First;
		if (num_rests > 1) {
			rest_time += (num_rests - 1) * Stop_Next;
		}
	}
	Result_Time_Centaur = movement_time + rest_time;
	return Result_Time_Centaur;
};