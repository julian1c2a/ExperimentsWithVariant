//
// Created by Julian Calderon Almendros on 04/05/2023.
//

#ifndef GUARD_EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP
#define GUARD_EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP

#include "wrapped_uint.hpp"
#include <variant>
#include <type_traits>

namespace experiments_with_variant {

    using std::false_type;
    using std::true_type;

    template<unsigned int N>
    using wuint = wrapped_uint<N>;

    using wrapped_uint_variant = std::variant<
            false_type, true_type, wuint<2>, wuint<3>, wuint<4>, wuint<5>, wuint<6>, wuint<7>, wuint<8>, wuint<9>,
            wuint<10>, wuint<11>, wuint<12>, wuint<13>, wuint<14>, wuint<15>, wuint<16>, wuint<17>, wuint<18>, wuint<19>,
            wuint<20>, wuint<21>, wuint<22>, wuint<23>, wuint<24>, wuint<25>, wuint<26>, wuint<27>, wuint<28>, wuint<29>,
            wuint<30>, wuint<31>, wuint<32>, wuint<33>, wuint<34>, wuint<35>, wuint<36>, wuint<37>, wuint<38>, wuint<39>,
            wuint<40>, wuint<41>, wuint<42>, wuint<43>, wuint<44>, wuint<45>, wuint<46>, wuint<47>, wuint<48>, wuint<49>,
            wuint<50>, wuint<51>, wuint<52>, wuint<53>, wuint<54>, wuint<55>, wuint<56>, wuint<57>, wuint<58>, wuint<59>,
            wuint<60>, wuint<61>, wuint<62>, wuint<63>, wuint<64>, wuint<65>, wuint<66>, wuint<67>, wuint<68>, wuint<69>,
            wuint<70>, wuint<71>, wuint<72>, wuint<73>, wuint<74>, wuint<75>, wuint<76>, wuint<77>, wuint<78>, wuint<79>,
            wuint<80>, wuint<81>, wuint<82>, wuint<83>, wuint<84>, wuint<85>, wuint<86>, wuint<87>, wuint<88>, wuint<89>,
            wuint<90>, wuint<91>, wuint<92>, wuint<93>, wuint<94>, wuint<95>, wuint<96>, wuint<97>, wuint<98>, wuint<99>,
            wuint<100>, wuint<101>, wuint<102>, wuint<103>, wuint<104>, wuint<105>, wuint<106>, wuint<107>, wuint<108>, wuint<109>,
            wuint<110>, wuint<111>, wuint<112>, wuint<113>, wuint<114>, wuint<115>, wuint<116>, wuint<117>, wuint<118>, wuint<119>,
            wuint<120>, wuint<121>, wuint<122>, wuint<123>, wuint<124>, wuint<125>, wuint<126>, wuint<127>, wuint<128>, wuint<129>,
            wuint<130>, wuint<131>, wuint<132>, wuint<133>, wuint<134>, wuint<135>, wuint<136>, wuint<137>, wuint<138>, wuint<139>,
            wuint<140>, wuint<141>, wuint<142>, wuint<143>, wuint<144>, wuint<145>, wuint<146>, wuint<147>, wuint<148>, wuint<149>,
            wuint<150>, wuint<151>, wuint<152>, wuint<153>, wuint<154>, wuint<155>, wuint<156>, wuint<157>, wuint<158>, wuint<159>,
            wuint<160>, wuint<161>, wuint<162>, wuint<163>, wuint<164>, wuint<165>, wuint<166>, wuint<167>, wuint<168>, wuint<169>,
            wuint<170>, wuint<171>, wuint<172>, wuint<173>, wuint<174>, wuint<175>, wuint<176>, wuint<177>, wuint<178>, wuint<179>,
            wuint<180>, wuint<181>, wuint<182>, wuint<183>, wuint<184>, wuint<185>, wuint<186>, wuint<187>, wuint<188>, wuint<189>,
            wuint<190>, wuint<191>, wuint<192>, wuint<193>, wuint<194>, wuint<195>, wuint<196>, wuint<197>, wuint<198>, wuint<199>,
            wuint<200>, wuint<201>, wuint<202>, wuint<203>, wuint<204>, wuint<205>, wuint<206>, wuint<207>, wuint<208>, wuint<209>,
            wuint<210>, wuint<211>, wuint<212>, wuint<213>, wuint<214>, wuint<215>, wuint<216>, wuint<217>, wuint<218>, wuint<219>,
            wuint<220>, wuint<221>, wuint<222>, wuint<223>, wuint<224>, wuint<225>, wuint<226>, wuint<227>, wuint<228>, wuint<229>,
            wuint<230>, wuint<231>, wuint<232>, wuint<233>, wuint<234>, wuint<235>, wuint<236>, wuint<237>, wuint<238>, wuint<239>,
            wuint<240>, wuint<241>, wuint<242>, wuint<243>, wuint<244>, wuint<245>, wuint<246>, wuint<247>, wuint<248>, wuint<249>,
            wuint<250>, wuint<251>, wuint<252>, wuint<253>, wuint<254>, wuint<255> >;

} // namespace experiments_with_variant
#endif //GUARD_EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP
