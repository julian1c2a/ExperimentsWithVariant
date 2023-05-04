//
// Created by julia on 04/05/2023.
//

#include "../include/wuintvariant_varlist.hpp"
#include <map>

namespace experiments_with_variant {
    [[maybe_unused]] bool wuintvariant_varlist::create_variable(const key_type& key, const value_type& value) noexcept {
        if (m_count < m_max_size) {
            if (m_list.find(key) != m_list.end()) {
                return false;
            } else {
                m_list.insert(std::pair<key_type, value_type>(key, value));
                ++m_count;
                return true;
            }
        }
        else {
            return false;
        }
    }

    bool wuintvariant_varlist::erase_variable(const wuintvariant_varlist::key_type &key) noexcept {
        if (m_count == 0) {
            return false;
        }
        else {
            if (m_list.find(key) != m_list.end()) {
                m_list.erase(key);
                --m_count;
                return true;
            }
            else {
                return false;
            }
        }
    }

    bool wuintvariant_varlist::create_variable(
            const std::pair<wuintvariant_varlist::key_type, wuintvariant_varlist::value_type> &node ) noexcept {
        return create_variable(std::get<0>(node),std::get<1>(node));
    }

    wuintvariant_varlist::value_type
    wuintvariant_varlist::get_variable(const wuintvariant_varlist::key_type &key) const noexcept {
        if (m_count == 0) {
            return {};
        }
        else {
            if (m_list.find(key) != m_list.end()) {
                return m_list.find(key)->second;
            }
            else {
                return {};
            }
        }
    }

    bool wuintvariant_varlist::exists_variable(const wuintvariant_varlist::key_type &key) const noexcept {
              return (m_list.find(key) != m_list.end());
    }

    bool wuintvariant_varlist::change_value(const wuintvariant_varlist::key_type &key,
                                            const wuintvariant_varlist::value_type &value) noexcept {
        if (m_count == 0) {
            return create_variable(key,value);
        }
        else if (m_count >= m_max_size) {
            return false;
        }
        else {
            if (m_list.find(key) != m_list.end()) {
                m_list.at(key) = value;
                return true;
            }
            else {
                return false;
            }
        }
    }

    bool wuintvariant_varlist::create_variable(const wuintvariant_varlist::key_type &key,
                                               wuintvariant_varlist::uint_type constintvalue,
                                               wuintvariant_varlist::uint_type raw_value) noexcept {
        using experiments_with_variant::wuint;
        if (m_count < m_max_size) {
            if (m_list.find(key) != m_list.end()) {
                return false;
            } else {
                switch(constintvalue){
                    case 0: return false;
                    case 1: return false;
                    case 2: m_list.insert({key,wuint<2>(raw_value)}); return true;
                    case 3: m_list.insert({key,wuint<3>(raw_value)}); return true;
                    case 4: m_list.insert({key,wuint<4>(raw_value)}); return true;
                    case 5: m_list.insert({key,wuint<5>(raw_value)}); return true;
                    case 6: m_list.insert({key,wuint<6>(raw_value)}); return true;
                    case 7: m_list.insert({key,wuint<7>(raw_value)}); return true;
                    case 8: m_list.insert({key,wuint<8>(raw_value)}); return true;
                    case 9: m_list.insert({key,wuint<9>(raw_value)}); return true;
                    case 10: m_list.insert({key,wuint<10>(raw_value)}); return true;
                    case 11: m_list.insert({key,wuint<11>(raw_value)}); return true;
                    case 12: m_list.insert({key,wuint<12>(raw_value)}); return true;
                    case 13: m_list.insert({key,wuint<13>(raw_value)}); return true;
                    case 14: m_list.insert({key,wuint<14>(raw_value)}); return true;
                    case 15: m_list.insert({key,wuint<15>(raw_value)}); return true;
                    case 16: m_list.insert({key,wuint<16>(raw_value)}); return true;
                    case 17: m_list.insert({key,wuint<17>(raw_value)}); return true;
                    case 18: m_list.insert({key,wuint<18>(raw_value)}); return true;
                    case 19: m_list.insert({key,wuint<19>(raw_value)}); return true;
                    case 20: m_list.insert({key,wuint<20>(raw_value)}); return true;
                    case 21: m_list.insert({key,wuint<21>(raw_value)}); return true;
                    case 22: m_list.insert({key,wuint<22>(raw_value)}); return true;
                    case 23: m_list.insert({key,wuint<23>(raw_value)}); return true;
                    case 24: m_list.insert({key,wuint<24>(raw_value)}); return true;
                    case 25: m_list.insert({key,wuint<25>(raw_value)}); return true;
                    case 26: m_list.insert({key,wuint<26>(raw_value)}); return true;
                    case 27: m_list.insert({key,wuint<27>(raw_value)}); return true;
                    case 28: m_list.insert({key,wuint<28>(raw_value)}); return true;
                    case 29: m_list.insert({key,wuint<29>(raw_value)}); return true;
                    case 30: m_list.insert({key,wuint<30>(raw_value)}); return true;
                    case 31: m_list.insert({key,wuint<31>(raw_value)}); return true;
                    case 32: m_list.insert({key,wuint<32>(raw_value)}); return true;
                    case 33: m_list.insert({key,wuint<33>(raw_value)}); return true;
                    case 34: m_list.insert({key,wuint<34>(raw_value)}); return true;
                    case 35: m_list.insert({key,wuint<35>(raw_value)}); return true;
                    case 36: m_list.insert({key,wuint<36>(raw_value)}); return true;
                    case 37: m_list.insert({key,wuint<37>(raw_value)}); return true;
                    case 38: m_list.insert({key,wuint<38>(raw_value)}); return true;
                    case 39: m_list.insert({key,wuint<39>(raw_value)}); return true;
                    case 40: m_list.insert({key,wuint<40>(raw_value)}); return true;
                    case 41: m_list.insert({key,wuint<41>(raw_value)}); return true;
                    case 42: m_list.insert({key,wuint<42>(raw_value)}); return true;
                    case 43: m_list.insert({key,wuint<43>(raw_value)}); return true;
                    case 44: m_list.insert({key,wuint<44>(raw_value)}); return true;
                    case 45: m_list.insert({key,wuint<45>(raw_value)}); return true;
                    case 46: m_list.insert({key,wuint<46>(raw_value)}); return true;
                    case 47: m_list.insert({key,wuint<47>(raw_value)}); return true;
                    case 48: m_list.insert({key,wuint<48>(raw_value)}); return true;
                    case 49: m_list.insert({key,wuint<49>(raw_value)}); return true;
                    case 50: m_list.insert({key,wuint<50>(raw_value)}); return true;
                    case 51: m_list.insert({key,wuint<51>(raw_value)}); return true;
                    case 52: m_list.insert({key,wuint<52>(raw_value)}); return true;
                    case 53: m_list.insert({key,wuint<53>(raw_value)}); return true;
                    case 54: m_list.insert({key,wuint<54>(raw_value)}); return true;
                    case 55: m_list.insert({key,wuint<55>(raw_value)}); return true;
                    case 56: m_list.insert({key,wuint<56>(raw_value)}); return true;
                    case 57: m_list.insert({key,wuint<57>(raw_value)}); return true;
                    case 58: m_list.insert({key,wuint<58>(raw_value)}); return true;
                    case 59: m_list.insert({key,wuint<59>(raw_value)}); return true;
                    case 60: m_list.insert({key,wuint<60>(raw_value)}); return true;
                    case 61: m_list.insert({key,wuint<61>(raw_value)}); return true;
                    case 62: m_list.insert({key,wuint<62>(raw_value)}); return true;
                    case 63: m_list.insert({key,wuint<63>(raw_value)}); return true;
                    case 64: m_list.insert({key,wuint<64>(raw_value)}); return true;
                    case 65: m_list.insert({key,wuint<65>(raw_value)}); return true;
                    case 66: m_list.insert({key,wuint<66>(raw_value)}); return true;
                    case 67: m_list.insert({key,wuint<67>(raw_value)}); return true;
                    case 68: m_list.insert({key,wuint<68>(raw_value)}); return true;
                    case 69: m_list.insert({key,wuint<69>(raw_value)}); return true;
                    case 70: m_list.insert({key,wuint<70>(raw_value)}); return true;
                    case 71: m_list.insert({key,wuint<71>(raw_value)}); return true;
                    case 72: m_list.insert({key,wuint<72>(raw_value)}); return true;
                    case 73: m_list.insert({key,wuint<73>(raw_value)}); return true;
                    case 74: m_list.insert({key,wuint<74>(raw_value)}); return true;
                    case 75: m_list.insert({key,wuint<75>(raw_value)}); return true;
                    case 76: m_list.insert({key,wuint<76>(raw_value)}); return true;
                    case 77: m_list.insert({key,wuint<77>(raw_value)}); return true;
                    case 78: m_list.insert({key,wuint<78>(raw_value)}); return true;
                    case 79: m_list.insert({key,wuint<79>(raw_value)}); return true;
                    case 80: m_list.insert({key,wuint<80>(raw_value)}); return true;
                    case 81: m_list.insert({key,wuint<81>(raw_value)}); return true;
                    case 82: m_list.insert({key,wuint<82>(raw_value)}); return true;
                    case 83: m_list.insert({key,wuint<83>(raw_value)}); return true;
                    case 84: m_list.insert({key,wuint<84>(raw_value)}); return true;
                    case 85: m_list.insert({key,wuint<85>(raw_value)}); return true;
                    case 86: m_list.insert({key,wuint<86>(raw_value)}); return true;
                    case 87: m_list.insert({key,wuint<87>(raw_value)}); return true;
                    case 88: m_list.insert({key,wuint<88>(raw_value)}); return true;
                    case 89: m_list.insert({key,wuint<89>(raw_value)}); return true;
                    case 90: m_list.insert({key,wuint<90>(raw_value)}); return true;
                    case 91: m_list.insert({key,wuint<91>(raw_value)}); return true;
                    case 92: m_list.insert({key,wuint<92>(raw_value)}); return true;
                    case 93: m_list.insert({key,wuint<93>(raw_value)}); return true;
                    case 94: m_list.insert({key,wuint<94>(raw_value)}); return true;
                    case 95: m_list.insert({key,wuint<95>(raw_value)}); return true;
                    case 96: m_list.insert({key,wuint<96>(raw_value)}); return true;
                    case 97: m_list.insert({key,wuint<97>(raw_value)}); return true;
                    case 98: m_list.insert({key,wuint<98>(raw_value)}); return true;
                    case 99: m_list.insert({key,wuint<99>(raw_value)}); return true;
                    case 100: m_list.insert({key,wuint<100>(raw_value)}); return true;
                    case 101: m_list.insert({key,wuint<101>(raw_value)}); return true;
                    case 102: m_list.insert({key,wuint<102>(raw_value)}); return true;
                    case 103: m_list.insert({key,wuint<103>(raw_value)}); return true;
                    case 104: m_list.insert({key,wuint<104>(raw_value)}); return true;
                    case 105: m_list.insert({key,wuint<105>(raw_value)}); return true;
                    case 106: m_list.insert({key,wuint<106>(raw_value)}); return true;
                    case 107: m_list.insert({key,wuint<107>(raw_value)}); return true;
                    case 108: m_list.insert({key,wuint<108>(raw_value)}); return true;
                    case 109: m_list.insert({key,wuint<109>(raw_value)}); return true;
                    case 110: m_list.insert({key,wuint<110>(raw_value)}); return true;
                    case 111: m_list.insert({key,wuint<111>(raw_value)}); return true;
                    case 112: m_list.insert({key,wuint<112>(raw_value)}); return true;
                    case 113: m_list.insert({key,wuint<113>(raw_value)}); return true;
                    case 114: m_list.insert({key,wuint<114>(raw_value)}); return true;
                    case 115: m_list.insert({key,wuint<115>(raw_value)}); return true;
                    case 116: m_list.insert({key,wuint<116>(raw_value)}); return true;
                    case 117: m_list.insert({key,wuint<117>(raw_value)}); return true;
                    case 118: m_list.insert({key,wuint<118>(raw_value)}); return true;
                    case 119: m_list.insert({key,wuint<119>(raw_value)}); return true;
                    case 120: m_list.insert({key,wuint<120>(raw_value)}); return true;
                    case 121: m_list.insert({key,wuint<121>(raw_value)}); return true;
                    case 122: m_list.insert({key,wuint<122>(raw_value)}); return true;
                    case 123: m_list.insert({key,wuint<123>(raw_value)}); return true;
                    case 124: m_list.insert({key,wuint<124>(raw_value)}); return true;
                    case 125: m_list.insert({key,wuint<125>(raw_value)}); return true;
                    case 126: m_list.insert({key,wuint<126>(raw_value)}); return true;
                    case 127: m_list.insert({key,wuint<127>(raw_value)}); return true;
                    case 128: m_list.insert({key,wuint<128>(raw_value)}); return true;
                    case 129: m_list.insert({key,wuint<129>(raw_value)}); return true;
                    case 130: m_list.insert({key,wuint<130>(raw_value)}); return true;
                    case 131: m_list.insert({key,wuint<131>(raw_value)}); return true;
                    case 132: m_list.insert({key,wuint<132>(raw_value)}); return true;
                    case 133: m_list.insert({key,wuint<133>(raw_value)}); return true;
                    case 134: m_list.insert({key,wuint<134>(raw_value)}); return true;
                    case 135: m_list.insert({key,wuint<135>(raw_value)}); return true;
                    case 136: m_list.insert({key,wuint<136>(raw_value)}); return true;
                    case 137: m_list.insert({key,wuint<137>(raw_value)}); return true;
                    case 138: m_list.insert({key,wuint<138>(raw_value)}); return true;
                    case 139: m_list.insert({key,wuint<139>(raw_value)}); return true;
                    case 140: m_list.insert({key,wuint<140>(raw_value)}); return true;
                    case 141: m_list.insert({key,wuint<141>(raw_value)}); return true;
                    case 142: m_list.insert({key,wuint<142>(raw_value)}); return true;
                    case 143: m_list.insert({key,wuint<143>(raw_value)}); return true;
                    case 144: m_list.insert({key,wuint<144>(raw_value)}); return true;
                    case 145: m_list.insert({key,wuint<145>(raw_value)}); return true;
                    case 146: m_list.insert({key,wuint<146>(raw_value)}); return true;
                    case 147: m_list.insert({key,wuint<147>(raw_value)}); return true;
                    case 148: m_list.insert({key,wuint<148>(raw_value)}); return true;
                    case 149: m_list.insert({key,wuint<149>(raw_value)}); return true;
                    case 150: m_list.insert({key,wuint<150>(raw_value)}); return true;
                    case 151: m_list.insert({key,wuint<151>(raw_value)}); return true;
                    case 152: m_list.insert({key,wuint<152>(raw_value)}); return true;
                    case 153: m_list.insert({key,wuint<153>(raw_value)}); return true;
                    case 154: m_list.insert({key,wuint<154>(raw_value)}); return true;
                    case 155: m_list.insert({key,wuint<155>(raw_value)}); return true;
                    case 156: m_list.insert({key,wuint<156>(raw_value)}); return true;
                    case 157: m_list.insert({key,wuint<157>(raw_value)}); return true;
                    case 158: m_list.insert({key,wuint<158>(raw_value)}); return true;
                    case 159: m_list.insert({key,wuint<159>(raw_value)}); return true;
                    case 160: m_list.insert({key,wuint<160>(raw_value)}); return true;
                    case 161: m_list.insert({key,wuint<161>(raw_value)}); return true;
                    case 162: m_list.insert({key,wuint<162>(raw_value)}); return true;
                    case 163: m_list.insert({key,wuint<163>(raw_value)}); return true;
                    case 164: m_list.insert({key,wuint<164>(raw_value)}); return true;
                    case 165: m_list.insert({key,wuint<165>(raw_value)}); return true;
                    case 166: m_list.insert({key,wuint<166>(raw_value)}); return true;
                    case 167: m_list.insert({key,wuint<167>(raw_value)}); return true;
                    case 168: m_list.insert({key,wuint<168>(raw_value)}); return true;
                    case 169: m_list.insert({key,wuint<169>(raw_value)}); return true;
                    case 170: m_list.insert({key,wuint<170>(raw_value)}); return true;
                    case 171: m_list.insert({key,wuint<171>(raw_value)}); return true;
                    case 172: m_list.insert({key,wuint<172>(raw_value)}); return true;
                    case 173: m_list.insert({key,wuint<173>(raw_value)}); return true;
                    case 174: m_list.insert({key,wuint<174>(raw_value)}); return true;
                    case 175: m_list.insert({key,wuint<175>(raw_value)}); return true;
                    case 176: m_list.insert({key,wuint<176>(raw_value)}); return true;
                    case 177: m_list.insert({key,wuint<177>(raw_value)}); return true;
                    case 178: m_list.insert({key,wuint<178>(raw_value)}); return true;
                    case 179: m_list.insert({key,wuint<179>(raw_value)}); return true;
                    case 180: m_list.insert({key,wuint<180>(raw_value)}); return true;
                    case 181: m_list.insert({key,wuint<181>(raw_value)}); return true;
                    case 182: m_list.insert({key,wuint<182>(raw_value)}); return true;
                    case 183: m_list.insert({key,wuint<183>(raw_value)}); return true;
                    case 184: m_list.insert({key,wuint<184>(raw_value)}); return true;
                    case 185: m_list.insert({key,wuint<185>(raw_value)}); return true;
                    case 186: m_list.insert({key,wuint<186>(raw_value)}); return true;
                    case 187: m_list.insert({key,wuint<187>(raw_value)}); return true;
                    case 188: m_list.insert({key,wuint<188>(raw_value)}); return true;
                    case 189: m_list.insert({key,wuint<189>(raw_value)}); return true;
                    case 190: m_list.insert({key,wuint<190>(raw_value)}); return true;
                    case 191: m_list.insert({key,wuint<191>(raw_value)}); return true;
                    case 192: m_list.insert({key,wuint<192>(raw_value)}); return true;
                    case 193: m_list.insert({key,wuint<193>(raw_value)}); return true;
                    case 194: m_list.insert({key,wuint<194>(raw_value)}); return true;
                    case 195: m_list.insert({key,wuint<195>(raw_value)}); return true;
                    case 196: m_list.insert({key,wuint<196>(raw_value)}); return true;
                    case 197: m_list.insert({key,wuint<197>(raw_value)}); return true;
                    case 198: m_list.insert({key,wuint<198>(raw_value)}); return true;
                    case 199: m_list.insert({key,wuint<199>(raw_value)}); return true;
                    case 200: m_list.insert({key,wuint<200>(raw_value)}); return true;
                    case 201: m_list.insert({key,wuint<201>(raw_value)}); return true;
                    case 202: m_list.insert({key,wuint<202>(raw_value)}); return true;
                    case 203: m_list.insert({key,wuint<203>(raw_value)}); return true;
                    case 204: m_list.insert({key,wuint<204>(raw_value)}); return true;
                    case 205: m_list.insert({key,wuint<205>(raw_value)}); return true;
                    case 206: m_list.insert({key,wuint<206>(raw_value)}); return true;
                    case 207: m_list.insert({key,wuint<207>(raw_value)}); return true;
                    case 208: m_list.insert({key,wuint<208>(raw_value)}); return true;
                    case 209: m_list.insert({key,wuint<209>(raw_value)}); return true;
                    case 210: m_list.insert({key,wuint<210>(raw_value)}); return true;
                    case 211: m_list.insert({key,wuint<211>(raw_value)}); return true;
                    case 212: m_list.insert({key,wuint<212>(raw_value)}); return true;
                    case 213: m_list.insert({key,wuint<213>(raw_value)}); return true;
                    case 214: m_list.insert({key,wuint<214>(raw_value)}); return true;
                    case 215: m_list.insert({key,wuint<215>(raw_value)}); return true;
                    case 216: m_list.insert({key,wuint<216>(raw_value)}); return true;
                    case 217: m_list.insert({key,wuint<217>(raw_value)}); return true;
                    case 218: m_list.insert({key,wuint<218>(raw_value)}); return true;
                    case 219: m_list.insert({key,wuint<219>(raw_value)}); return true;
                    case 220: m_list.insert({key,wuint<220>(raw_value)}); return true;
                    case 221: m_list.insert({key,wuint<221>(raw_value)}); return true;
                    case 222: m_list.insert({key,wuint<222>(raw_value)}); return true;
                    case 223: m_list.insert({key,wuint<223>(raw_value)}); return true;
                    case 224: m_list.insert({key,wuint<224>(raw_value)}); return true;
                    case 225: m_list.insert({key,wuint<225>(raw_value)}); return true;
                    case 226: m_list.insert({key,wuint<226>(raw_value)}); return true;
                    case 227: m_list.insert({key,wuint<227>(raw_value)}); return true;
                    case 228: m_list.insert({key,wuint<228>(raw_value)}); return true;
                    case 229: m_list.insert({key,wuint<229>(raw_value)}); return true;
                    case 230: m_list.insert({key,wuint<230>(raw_value)}); return true;
                    case 231: m_list.insert({key,wuint<231>(raw_value)}); return true;
                    case 232: m_list.insert({key,wuint<232>(raw_value)}); return true;
                    case 233: m_list.insert({key,wuint<233>(raw_value)}); return true;
                    case 234: m_list.insert({key,wuint<234>(raw_value)}); return true;
                    case 235: m_list.insert({key,wuint<235>(raw_value)}); return true;
                    case 236: m_list.insert({key,wuint<236>(raw_value)}); return true;
                    case 237: m_list.insert({key,wuint<237>(raw_value)}); return true;
                    case 238: m_list.insert({key,wuint<238>(raw_value)}); return true;
                    case 239: m_list.insert({key,wuint<239>(raw_value)}); return true;
                    case 240: m_list.insert({key,wuint<240>(raw_value)}); return true;
                    case 241: m_list.insert({key,wuint<241>(raw_value)}); return true;
                    case 242: m_list.insert({key,wuint<242>(raw_value)}); return true;
                    case 243: m_list.insert({key,wuint<243>(raw_value)}); return true;
                    case 244: m_list.insert({key,wuint<244>(raw_value)}); return true;
                    case 245: m_list.insert({key,wuint<245>(raw_value)}); return true;
                    case 246: m_list.insert({key,wuint<246>(raw_value)}); return true;
                    case 247: m_list.insert({key,wuint<247>(raw_value)}); return true;
                    case 248: m_list.insert({key,wuint<248>(raw_value)}); return true;
                    case 249: m_list.insert({key,wuint<249>(raw_value)}); return true;
                    case 250: m_list.insert({key,wuint<250>(raw_value)}); return true;
                    case 251: m_list.insert({key,wuint<251>(raw_value)}); return true;
                    case 252: m_list.insert({key,wuint<252>(raw_value)}); return true;
                    case 253: m_list.insert({key,wuint<253>(raw_value)}); return true;
                    case 254: m_list.insert({key,wuint<254>(raw_value)}); return true;
                    case 255: m_list.insert({key,wuint<255>(raw_value)}); return true;
                    default : return false;
                }
            }
        }
        else {
            return false;
        }
    }
} // experiments_with_variant