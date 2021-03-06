/**
 * @brief Contains the declaration of MotorEfficiency25 class including the getters and setters as well as the calculators
 *          for motor efficiency.
 *      calculate(): Calculates the motor efficiency givenat 25% intervals of load factor.
 *
 * @author Subhankar Mishra (mishras)
 * @bug No known bugs.
 *
 */

#ifndef UNTITLED_MOTOREFFICIENCY25_H
#define UNTITLED_MOTOREFFICIENCY25_H

#include <vector>
#include "psat/Motor.h"

class MotorEfficiency25 {
public:
    /**
     * Constructor
     * @param efficiencyClass Motor::EfficiencyClass, Efficiency class of motor
     * @param motorRatedPower double, Rated power of motor in hp
     * @param motorRpm double, Rpm of motor
     * @param lineFrequency Motor::LineFrequency, classification of line frequency in Hz
     * @return nothing
     */
    MotorEfficiency25(
        Motor::EfficiencyClass efficiencyClass,
        double motorRatedPower,
        double motorRpm,
        Motor::LineFrequency lineFrequency
    ) :
        efficiencyClass_(efficiencyClass),
        motorRatedPower_(motorRatedPower),
        motorRpm_(motorRpm),
        lineFrequency_(lineFrequency)
    {};

    /**
     *
     * @return Vector containing motor efficiency as %
     */
    std::vector<double> calculate();

private:
    /**
     * Efficiency class of motor
     */
    Motor::EfficiencyClass efficiencyClass_;
    /**
     * Rated power of motor in hp
     */
    double motorRatedPower_;
    /**
     * Rpm of motor
     */
    double motorRpm_;
    /**
     * Line Frequency of motor
     */
    Motor::LineFrequency lineFrequency_;
};


#endif //UNTITLED_MOTOREFFICIENCY25_H
