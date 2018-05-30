/**
	AverageSensor.h - Reads a signal from a delegated sensor,
	averages the signal and return it.

	Instantiation:
	  Sensor otherSensor();
		AverageSensor sensor(otherSensor, 0, 100);

	Read signal:
		sensor.read();

	https://github.com/YuriiSalimov/AD_Sensors

	Created by Yurii Salimov, May, 2018.
	Released into the public domain.
*/
#ifndef AVERAGE_SENSOR_H
#define AVERAGE_SENSOR_H

#include <Sensor.h>

#define AVERAGE_SENSOR_MIN_COUNTER 1
#define AVERAGE_SENSOR_MIN_TIME_DELAY 1

class AverageSensor final :
  public Sensor {

	private:
		const Sensor* sensor;
		int counter = 0;
		int delayTime = 0;

	public:
		AverageSensor(
			const Sensor* sensor,
			const int counter,
			const int delayTime
		);

		int read() override;

	private:
		void sleep();
};

#endif