//
// Created by Julian Calderon Almendros on 04/05/2023.
//

#ifndef EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP
#define EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP

#include "wrapped_uint.hpp"
#include <variant>
#include <utility>
#include <type_traits>

namespace experimentsWithVariant {

using std::false_type;
using std::true_type;

template<unsigned int N>
using wuint = wrapped_uint<N>;

template<typename ... Ts>
using variant = typename std::variant<Ts...>;

using wrapped_uint_variant = variant<
        false_type,true_type, wuint< 2>, wuint< 3>, wuint< 4>, wuint< 5>, wuint< 6>, wuint< 7>, wuint< 8>, wuint< 9>,
        wuint<10>, wuint<11>, wuint<12>, wuint<13>, wuint<14>, wuint<15>, wuint<16>, wuint<17>, wuint<18>, wuint<19>,
        wuint<20>, wuint<21>, wuint<22>, wuint<23>, wuint<24>, wuint<25>, wuint<26>, wuint<27>, wuint<28>, wuint<29>,
        wuint<30>, wuint<31>, wuint<32>, wuint<33>, wuint<34>, wuint<35>, wuint<36>, wuint<37>, wuint<38>, wuint<39>,
        wuint<40>, wuint<41>, wuint<42>, wuint<43>, wuint<44>, wuint<45>, wuint<46>, wuint<47>, wuint<48>, wuint<49>,
        wuint<50>, wuint<51>, wuint<52>, wuint<53>, wuint<54>, wuint<55>, wuint<56>, wuint<57>, wuint<58>, wuint<59>,
        wuint<60>, wuint<61>, wuint<62>, wuint<63>
    >;

} // namespace experimentsWithVariant
#endif //EXPERIMENTSWITHVARIANT_VARIANT_TYPE_HPP
