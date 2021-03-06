/**
 * @brief Header file for OptimalSpecificSpeedCorrection class
 *
 * This contains the prototypes of Optimal Specific Speed Correction calculator including getters and setters for the important fields.
 *
 * @author Subhankar Mishra (mishras)
 * @bug No known bugs.
 *
 */

#ifndef AMO_LIBRARY_OPTIMALSPECIFICSPEEDCORRECTION_H
#define AMO_LIBRARY_OPTIMALSPECIFICSPEEDCORRECTION_H

#include "psat/Pump.h"

class OptimalSpecificSpeedCorrection {
public:
    /**
     * Constructor
     * @param style Pump::Style, type of pump speed from either fixed or not fixed.
     * @param specificSpeed double, specific speed in rpm*sqrt(gpm)/((ft/s)^(3/2))
     * @return nothing
     */
    OptimalSpecificSpeedCorrection(
        Pump::Style style,
        double specificSpeed
    ):
        specificSpeed_(specificSpeed),
        style_(style)
    {};

    /**
     * Calculates the optimal specific speed correction
     *
     * @return double, optimal specific speed correction as %
     */
    double calculate();

private:
    double specificSpeed_;
    Pump::Style style_;

    double specificSpeedCorrection_ = 0.0;
};


#endif //AMO_LIBRARY_OPTIMALSPECIFICSPEEDCORRECTION_H
