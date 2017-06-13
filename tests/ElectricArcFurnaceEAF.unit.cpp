#include "catch.hpp"
#include <calculator/losses/ElectricArcFurnaceEAF.h>

TEST_CASE( "Calculate the Natural Gas Heat", "[Natural Gas Heat][ElectricArcFurnaceEAF][Furnace]") {
    CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getNaturalGasHeat() == Approx(0.0));
}

TEST_CASE( "Calculate the Coal Heat Content", "[Coal Heat Content][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getCoalHeatContent() == Approx(29.70));
}

TEST_CASE( "Calculate the Electrode Heat Content", "[Electrode Heat Content][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getElectrodeHeatContent() == Approx(6.0));
}

TEST_CASE( "Calculate the Total Chemical Energy Input", "[Total Chemical Energy Input][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getTotalChemicalEnergyInput() == Approx(105.7));
}

TEST_CASE( "Calculate the kwh Cycle", "[kwh Cycle][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getKwhCycle() == Approx(30978.9));
}

TEST_CASE( "Calculate the Heat Delivered", "[Heat Delivered][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getHeatDelivered() == Approx(55.7));
}

TEST_CASE( "Calculate the Total kwh/Cycle", "[Total kwh/Cycle][ElectricArcFurnaceEAF][Furnace]") {
CHECK( ElectricArcFurnaceEAF(50, 0, 6500, 3300, 9000, 500, 12000, 20, 18000).getTotalKwhPerCycle() == Approx(48978.898007034));
}


