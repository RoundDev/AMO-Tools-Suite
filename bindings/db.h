//
// Created by Accawi, Gina K. on 3/13/17.
//

#ifndef AMO_TOOLS_SUITE_DB_H
#define AMO_TOOLS_SUITE_DB_H
#include <nan.h>
#include <node.h>
#include <sqlite/SQLite.h>
#include <fstream>
#include <memory>
#include <calculator/losses/SolidLoadChargeMaterial.h>
#include <calculator/losses/LiquidLoadChargeMaterial.h>
#include <calculator/losses/GasLoadChargeMaterial.h>
#include <calculator/losses/GasFlueGasMaterial.h>
#include <calculator/losses/SolidLiquidFlueGasMaterial.h>

using namespace Nan;
using namespace v8;

std::unique_ptr<SQLite> sql;

    NAN_METHOD(startup) {
	    std::string dbName = ":memory:";
	    sql = std::unique_ptr<SQLite>(new SQLite(dbName, true));
    }

    NAN_METHOD(update) {
//        db migration code goes here
    }

    NAN_METHOD(selectSolidLoadChargeMaterials) {
	    Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> specificHeatSolid = Nan::New<String>("specificHeatSolid").ToLocalChecked();
        Local<String> latentHeat = Nan::New<String>("latentHeat").ToLocalChecked();
        Local<String> specificHeatLiquid = Nan::New<String>("specificHeatLiquid").ToLocalChecked();
        Local<String> meltingPoint = Nan::New<String>("meltingPoint").ToLocalChecked();

        auto const slcms = sql->getSolidLoadChargeMaterials();

        auto objs = Nan::New<v8::Array>();
        for ( size_t i = 0; i < slcms.size(); i++ ) {
            auto const slcm = slcms[i];
            Local<Object> obj = Nan::New<Object>();
            Nan::Set(obj, id, Nan::New<Number>(slcm.getID()));
            Nan::Set(obj, substance, Nan::New<String>(slcm.getSubstance()).ToLocalChecked());
            Nan::Set(obj, specificHeatSolid, Nan::New<Number>(slcm.getSpecificHeatSolid()));
            Nan::Set(obj, latentHeat, Nan::New<Number>(slcm.getLatentHeat()));
            Nan::Set(obj, specificHeatLiquid, Nan::New<Number>(slcm.getSpecificHeatLiquid()));
            Nan::Set(obj, meltingPoint, Nan::New<Number>(slcm.getMeltingPoint()));
	        Nan::Set(objs, i, obj);
        }

        info.GetReturnValue().Set(objs);
    }

    NAN_METHOD(selectSolidLoadChargeMaterialById) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> specificHeatSolid = Nan::New<String>("specificHeatSolid").ToLocalChecked();
        Local<String> latentHeat = Nan::New<String>("latentHeat").ToLocalChecked();
        Local<String> specificHeatLiquid = Nan::New<String>("specificHeatLiquid").ToLocalChecked();
        Local<String> meltingPoint = Nan::New<String>("meltingPoint").ToLocalChecked();

	    auto const slcm = sql->getSolidLoadChargeMaterialById(info[0]->NumberValue());

        Local<Object> obj = Nan::New<Object>();
        Nan::Set(obj, id, Nan::New<Number>(slcm.getID()));
        Nan::Set(obj, substance, Nan::New<String>(slcm.getSubstance()).ToLocalChecked());
        Nan::Set(obj, specificHeatSolid, Nan::New<Number>(slcm.getSpecificHeatSolid()));
        Nan::Set(obj, latentHeat, Nan::New<Number>(slcm.getLatentHeat()));
        Nan::Set(obj, specificHeatLiquid, Nan::New<Number>(slcm.getSpecificHeatLiquid()));
        Nan::Set(obj, meltingPoint, Nan::New<Number>(slcm.getMeltingPoint()));

        info.GetReturnValue().Set(obj);
    }

    NAN_METHOD(selectLiquidLoadChargeMaterials) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> specificHeatLiquid = Nan::New<String>("specificHeatLiquid").ToLocalChecked();
        Local<String> specificHeatVapor = Nan::New<String>("specificHeatVapor").ToLocalChecked();
        Local<String> vaporizationTemperature = Nan::New<String>("vaporizationTemperature").ToLocalChecked();
        Local<String> latentHeat = Nan::New<String>("latentHeat").ToLocalChecked();

        auto const llcms = sql->getLiquidLoadChargeMaterials();

        auto objs = Nan::New<v8::Array>();
        for ( size_t i = 0; i < llcms.size(); i++ ) {
	        auto const llcm = llcms[i];
            Local<Object> obj = Nan::New<Object>();
            Nan::Set(obj, id, Nan::New<Number>(llcm.getID()));
            Nan::Set(obj, substance, Nan::New<String>(llcm.getSubstance()).ToLocalChecked());
            Nan::Set(obj, specificHeatLiquid, Nan::New<Number>(llcm.getSpecificHeatLiquid()));
            Nan::Set(obj, specificHeatVapor, Nan::New<Number>(llcm.getSpecificHeatVapor()));
            Nan::Set(obj, vaporizationTemperature, Nan::New<Number>(llcm.getVaporizingTemperature()));
            Nan::Set(obj, latentHeat, Nan::New<Number>(llcm.getLatentHeat()));
            Nan::Set(objs, i, obj);
        }

        info.GetReturnValue().Set(objs);
    }

    NAN_METHOD(selectLiquidLoadChargeMaterialById) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> specificHeatLiquid = Nan::New<String>("specificHeatLiquid").ToLocalChecked();
        Local<String> specificHeatVapor = Nan::New<String>("specificHeatVapor").ToLocalChecked();
        Local<String> vaporizationTemperature = Nan::New<String>("vaporizationTemperature").ToLocalChecked();
        Local<String> latentHeat = Nan::New<String>("latentHeat").ToLocalChecked();

        auto const llcm = sql->getLiquidLoadChargeMaterialById(info[0]->NumberValue());

        Local<Object> obj = Nan::New<Object>();
        Nan::Set(obj, id, Nan::New<Number>(llcm.getID()));
        Nan::Set(obj, substance, Nan::New<String>(llcm.getSubstance()).ToLocalChecked());
        Nan::Set(obj, specificHeatLiquid, Nan::New<Number>(llcm.getSpecificHeatLiquid()));
        Nan::Set(obj, specificHeatVapor, Nan::New<Number>(llcm.getSpecificHeatVapor()));
        Nan::Set(obj, vaporizationTemperature, Nan::New<Number>(llcm.getVaporizingTemperature()));
        Nan::Set(obj, latentHeat, Nan::New<Number>(llcm.getLatentHeat()));

        info.GetReturnValue().Set(obj);
    }

    NAN_METHOD(selectGasLoadChargeMaterials) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> specificHeatVapor = Nan::New<String>("specificHeatVapor").ToLocalChecked();

        auto const glcms = sql->getGasLoadChargeMaterials();

        auto objs = Nan::New<v8::Array>();
        for ( size_t i = 0; i < glcms.size(); i++ ) {
            auto const glcm = glcms[i];
            Local<Object> obj = Nan::New<Object>();
            Nan::Set(obj, id, Nan::New<Number>(glcm.getID()));
            Nan::Set(obj, substance, Nan::New<String>(glcm.getSubstance()).ToLocalChecked());
            Nan::Set(obj, specificHeatVapor, Nan::New<Number>(glcm.getSpecificHeatVapor()));
            Nan::Set(objs, i, obj);
        }

        info.GetReturnValue().Set(objs);
    }

    NAN_METHOD(selectGasLoadChargeMaterialById) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
	    Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
	    Local<String> specificHeatVapor = Nan::New<String>("specificHeatVapor").ToLocalChecked();

	    auto const glcm = sql->getGasLoadChargeMaterialById(info[0]->NumberValue());

	    Local<Object> obj = Nan::New<Object>();
        Nan::Set(obj, id, Nan::New<Number>(glcm.getID()));
	    Nan::Set(obj, substance, Nan::New<String>(glcm.getSubstance()).ToLocalChecked());
	    Nan::Set(obj, specificHeatVapor, Nan::New<Number>(glcm.getSpecificHeatVapor()));

	    info.GetReturnValue().Set(obj);
    }

    NAN_METHOD(selectSolidLiquidFlueGasMaterials) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> carbon = Nan::New<String>("carbon").ToLocalChecked();
        Local<String> hydrogen = Nan::New<String>("hydrogen").ToLocalChecked();
        Local<String> sulphur = Nan::New<String>("sulphur").ToLocalChecked();
        Local<String> inertAsh = Nan::New<String>("inertAsh").ToLocalChecked();
        Local<String> o2 = Nan::New<String>("o2").ToLocalChecked();
        Local<String> moisture = Nan::New<String>("moisture").ToLocalChecked();
        Local<String> nitrogen = Nan::New<String>("nitrogen").ToLocalChecked();

        auto const fgMaterials = sql->getSolidLiquidFlueGasMaterials();

        auto objs = Nan::New<v8::Array>();
        for ( size_t i = 0; i < fgMaterials.size(); i++ ) {
            auto const fgm = fgMaterials[i];
            Local<Object> obj = Nan::New<Object>();
            Nan::Set(obj, id, Nan::New<Number>(fgm.getID()));
            Nan::Set(obj, substance, Nan::New<String>(fgm.getSubstance()).ToLocalChecked());
            Nan::Set(obj, carbon, Nan::New<Number>(fgm.getCarbon()));
            Nan::Set(obj, hydrogen, Nan::New<Number>(fgm.getHydrogen()));
            Nan::Set(obj, sulphur, Nan::New<Number>(fgm.getSulphur()));
            Nan::Set(obj, inertAsh, Nan::New<Number>(fgm.getInertAsh()));
            Nan::Set(obj, o2, Nan::New<Number>(fgm.getO2()));
            Nan::Set(obj, moisture, Nan::New<Number>(fgm.getMoisture()));
            Nan::Set(obj, nitrogen, Nan::New<Number>(fgm.getNitrogen()));
            Nan::Set(objs, i, obj);
        }

        info.GetReturnValue().Set(objs);
    };

    NAN_METHOD(selectSolidLiquidFlueGasMaterialById) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> carbon = Nan::New<String>("carbon").ToLocalChecked();
        Local<String> hydrogen = Nan::New<String>("hydrogen").ToLocalChecked();
        Local<String> sulphur = Nan::New<String>("sulphur").ToLocalChecked();
        Local<String> inertAsh = Nan::New<String>("inertAsh").ToLocalChecked();
        Local<String> o2 = Nan::New<String>("o2").ToLocalChecked();
        Local<String> moisture = Nan::New<String>("moisture").ToLocalChecked();
        Local<String> nitrogen = Nan::New<String>("nitrogen").ToLocalChecked();

        auto const fgm = sql->getSolidLiquidFlueGasMaterialById(info[0]->NumberValue());
        Local<Object> obj = Nan::New<Object>();
        Nan::Set(obj, id, Nan::New<Number>(fgm.getID()));
        Nan::Set(obj, substance, Nan::New<String>(fgm.getSubstance()).ToLocalChecked());
        Nan::Set(obj, carbon, Nan::New<Number>(fgm.getCarbon()));
        Nan::Set(obj, hydrogen, Nan::New<Number>(fgm.getHydrogen()));
        Nan::Set(obj, sulphur, Nan::New<Number>(fgm.getSulphur()));
        Nan::Set(obj, inertAsh, Nan::New<Number>(fgm.getInertAsh()));
        Nan::Set(obj, o2, Nan::New<Number>(fgm.getO2()));
        Nan::Set(obj, moisture, Nan::New<Number>(fgm.getMoisture()));
        Nan::Set(obj, nitrogen, Nan::New<Number>(fgm.getNitrogen()));

        info.GetReturnValue().Set(obj);
    };

    NAN_METHOD(selectGasFlueGasMaterials) {
	    Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> CH4 = Nan::New<String>("CH4").ToLocalChecked();
        Local<String> C2H6 = Nan::New<String>("C2H6").ToLocalChecked();
        Local<String> N2 = Nan::New<String>("N2").ToLocalChecked();
        Local<String> H2 = Nan::New<String>("H2").ToLocalChecked();
        Local<String> C3H8 = Nan::New<String>("C3H8").ToLocalChecked();
        Local<String> C4H10_CnH2n = Nan::New<String>("C4H10_CnH2n").ToLocalChecked();
        Local<String> H2O = Nan::New<String>("H2O").ToLocalChecked();
        Local<String> CO = Nan::New<String>("CO").ToLocalChecked();
        Local<String> CO2 = Nan::New<String>("CO2").ToLocalChecked();
        Local<String> SO2 = Nan::New<String>("SO2").ToLocalChecked();
        Local<String> O2 = Nan::New<String>("O2").ToLocalChecked();

        auto const fgMaterials = sql->getGasFlueGasMaterials();

        auto objs = Nan::New<v8::Array>();
        for ( size_t i = 0; i < fgMaterials.size(); i++ ) {
            auto const fgm = fgMaterials[i];
            Local<Object> obj = Nan::New<Object>();
            Nan::Set(obj, id, Nan::New<Number>(fgm.getID()));
            Nan::Set(obj, substance, Nan::New<String>(fgm.getSubstance()).ToLocalChecked());
            Nan::Set(obj, CH4, Nan::New<Number>(fgm.getGasByVol("CH4")));
            Nan::Set(obj, C2H6, Nan::New<Number>(fgm.getGasByVol("C2H6")));
            Nan::Set(obj, N2, Nan::New<Number>(fgm.getGasByVol("N2")));
            Nan::Set(obj, H2, Nan::New<Number>(fgm.getGasByVol("H2")));
            Nan::Set(obj, C3H8, Nan::New<Number>(fgm.getGasByVol("C3H8")));
            Nan::Set(obj, C4H10_CnH2n, Nan::New<Number>(fgm.getGasByVol("C4H10_CnH2n")));
            Nan::Set(obj, H2O, Nan::New<Number>(fgm.getGasByVol("H2O")));
            Nan::Set(obj, CO, Nan::New<Number>(fgm.getGasByVol("CO")));
            Nan::Set(obj, CO2, Nan::New<Number>(fgm.getGasByVol("CO2")));
            Nan::Set(obj, SO2, Nan::New<Number>(fgm.getGasByVol("SO2")));
            Nan::Set(obj, O2, Nan::New<Number>(fgm.getGasByVol("O2")));
            Nan::Set(objs, i, obj);
        }

        info.GetReturnValue().Set(objs);
    };

    NAN_METHOD(selectGasFlueGasMaterialById) {
        Local<String> id = Nan::New<String>("id").ToLocalChecked();
        Local<String> substance = Nan::New<String>("substance").ToLocalChecked();
        Local<String> CH4 = Nan::New<String>("CH4").ToLocalChecked();
        Local<String> C2H6 = Nan::New<String>("C2H6").ToLocalChecked();
        Local<String> N2 = Nan::New<String>("N2").ToLocalChecked();
        Local<String> H2 = Nan::New<String>("H2").ToLocalChecked();
        Local<String> C3H8 = Nan::New<String>("C3H8").ToLocalChecked();
        Local<String> C4H10_CnH2n = Nan::New<String>("C4H10_CnH2n").ToLocalChecked();
        Local<String> H2O = Nan::New<String>("H2O").ToLocalChecked();
        Local<String> CO = Nan::New<String>("CO").ToLocalChecked();
        Local<String> CO2 = Nan::New<String>("CO2").ToLocalChecked();
        Local<String> SO2 = Nan::New<String>("SO2").ToLocalChecked();
        Local<String> O2 = Nan::New<String>("O2").ToLocalChecked();

        auto const fgm = sql->getGasFlueGasMaterialById(info[0]->NumberValue());

        Local<Object> obj = Nan::New<Object>();
        Nan::Set(obj, id, Nan::New<Number>(fgm.getID()));
        Nan::Set(obj, substance, Nan::New<String>(fgm.getSubstance()).ToLocalChecked());
        Nan::Set(obj, CH4, Nan::New<Number>(fgm.getGasByVol("CH4")));
        Nan::Set(obj, C2H6, Nan::New<Number>(fgm.getGasByVol("C2H6")));
        Nan::Set(obj, N2, Nan::New<Number>(fgm.getGasByVol("N2")));
        Nan::Set(obj, H2, Nan::New<Number>(fgm.getGasByVol("H2")));
        Nan::Set(obj, C3H8, Nan::New<Number>(fgm.getGasByVol("C3H8")));
        Nan::Set(obj, C4H10_CnH2n, Nan::New<Number>(fgm.getGasByVol("C4H10_CnH2n")));
        Nan::Set(obj, H2O, Nan::New<Number>(fgm.getGasByVol("H2O")));
        Nan::Set(obj, CO, Nan::New<Number>(fgm.getGasByVol("CO")));
        Nan::Set(obj, CO2, Nan::New<Number>(fgm.getGasByVol("CO2")));
        Nan::Set(obj, SO2, Nan::New<Number>(fgm.getGasByVol("SO2")));
        Nan::Set(obj, O2, Nan::New<Number>(fgm.getGasByVol("O2")));

        info.GetReturnValue().Set(obj);
    };


#endif //AMO_TOOLS_SUITE_DB_H
