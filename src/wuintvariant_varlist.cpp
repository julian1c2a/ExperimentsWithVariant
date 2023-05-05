//
// Created by Julian Calderon Almendros on 04/05/2023.
//

#include "../include/wuintvariant_varlist.hpp"
#include <map>

namespace experimentsWithVariant {

    bool wuintvariant_varlist::create_variable(const key_type& key, const value_type& value) noexcept {
        if (m_count < m_max_count) {
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
    }  // end of method or member function

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
    }  // end of method or member function

    bool wuintvariant_varlist::create_variable(
            const std::pair<wuintvariant_varlist::key_type, wuintvariant_varlist::value_type> &node ) noexcept {
        return create_variable(std::get<0>(node),std::get<1>(node));
    }  // end of method or member function

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
    }  // end of method or member function

    bool wuintvariant_varlist::exists_variable(const wuintvariant_varlist::key_type &key) const noexcept {
              return (m_list.find(key) != m_list.end());
    }  // end of method or member function

    bool wuintvariant_varlist::change_value(const wuintvariant_varlist::key_type &key,
                                            const wuintvariant_varlist::value_type &value) noexcept {
        if (m_count == 0) {
            return create_variable(key,value);
        }
        else if (m_count >= m_max_count) {
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
    } // end of method or member function

    bool wuintvariant_varlist::create_variable(
        const wuintvariant_varlist::key_type &key,
        wuintvariant_varlist::uint_type constintvalue,
        wuintvariant_varlist::uint_type raw_value
    ) noexcept {

        using experimentsWithVariant::wuint;

        if (m_count < m_max_count) {
            if (m_list.find(key) != m_list.end()) {
                return false;
            } else {
                switch(constintvalue){
                    case  0: return false;
                    case  1: return false;
                    case  2: return create_variable(key,wuint< 2>(raw_value));
                    case  3: return create_variable(key,wuint< 3>(raw_value));
                    case  4: return create_variable(key,wuint< 4>(raw_value));
                    case  5: return create_variable(key,wuint< 5>(raw_value));
                    case  6: return create_variable(key,wuint< 6>(raw_value));
                    case  7: return create_variable(key,wuint< 7>(raw_value));
                    case  8: return create_variable(key,wuint< 8>(raw_value));
                    case  9: return create_variable(key,wuint< 9>(raw_value));
                    case 10: return create_variable(key,wuint<10>(raw_value));
                    case 11: return create_variable(key,wuint<11>(raw_value));
                    case 12: return create_variable(key,wuint<12>(raw_value));
                    case 13: return create_variable(key,wuint<13>(raw_value));
                    case 14: return create_variable(key,wuint<14>(raw_value));
                    case 15: return create_variable(key,wuint<15>(raw_value));
                    case 16: return create_variable(key,wuint<16>(raw_value));
                    case 17: return create_variable(key,wuint<17>(raw_value));
                    case 18: return create_variable(key,wuint<18>(raw_value));
                    case 19: return create_variable(key,wuint<19>(raw_value));
                    case 20: return create_variable(key,wuint<20>(raw_value));
                    case 21: return create_variable(key,wuint<21>(raw_value));
                    case 22: return create_variable(key,wuint<22>(raw_value));
                    case 23: return create_variable(key,wuint<23>(raw_value));
                    case 24: return create_variable(key,wuint<24>(raw_value));
                    case 25: return create_variable(key,wuint<25>(raw_value));
                    case 26: return create_variable(key,wuint<26>(raw_value));
                    case 27: return create_variable(key,wuint<27>(raw_value));
                    case 28: return create_variable(key,wuint<28>(raw_value));
                    case 29: return create_variable(key,wuint<29>(raw_value));
                    case 30: return create_variable(key,wuint<30>(raw_value));
                    case 31: return create_variable(key,wuint<31>(raw_value));
                    case 32: return create_variable(key,wuint<32>(raw_value));
                    case 33: return create_variable(key,wuint<33>(raw_value));
                    case 34: return create_variable(key,wuint<34>(raw_value));
                    case 35: return create_variable(key,wuint<35>(raw_value));
                    case 36: return create_variable(key,wuint<36>(raw_value));
                    case 37: return create_variable(key,wuint<37>(raw_value));
                    case 38: return create_variable(key,wuint<38>(raw_value));
                    case 39: return create_variable(key,wuint<39>(raw_value));
                    case 40: return create_variable(key,wuint<40>(raw_value));
                    case 41: return create_variable(key,wuint<41>(raw_value));
                    case 42: return create_variable(key,wuint<42>(raw_value));
                    case 43: return create_variable(key,wuint<43>(raw_value));
                    case 44: return create_variable(key,wuint<44>(raw_value));
                    case 45: return create_variable(key,wuint<45>(raw_value));
                    case 46: return create_variable(key,wuint<46>(raw_value));
                    case 47: return create_variable(key,wuint<47>(raw_value));
                    case 48: return create_variable(key,wuint<48>(raw_value));
                    case 49: return create_variable(key,wuint<49>(raw_value));
                    case 50: return create_variable(key,wuint<50>(raw_value));
                    case 51: return create_variable(key,wuint<51>(raw_value));
                    case 52: return create_variable(key,wuint<52>(raw_value));
                    case 53: return create_variable(key,wuint<53>(raw_value));
                    case 54: return create_variable(key,wuint<54>(raw_value));
                    case 55: return create_variable(key,wuint<55>(raw_value));
                    case 56: return create_variable(key,wuint<56>(raw_value));
                    case 57: return create_variable(key,wuint<57>(raw_value));
                    case 58: return create_variable(key,wuint<58>(raw_value));
                    case 59: return create_variable(key,wuint<59>(raw_value));
                    case 60: return create_variable(key,wuint<60>(raw_value));
                    case 61: return create_variable(key,wuint<61>(raw_value));
                    case 62: return create_variable(key,wuint<62>(raw_value));
                    case 63: return create_variable(key,wuint<63>(raw_value));
                    default : return false;
                }
            }
        }
        else {
            return false;
        }
    }

    bool wuintvariant_varlist::change_value(
        const wuintvariant_varlist::key_type& key,
        wuintvariant_varlist::uint_type base,
        wuintvariant_varlist::uint_type raw_value
    ) noexcept {

        using experimentsWithVariant::wuint;

        if (this->m_list.find(key) != this->m_list.end()) {
            switch(base)    {
                case  0: return false;
                case  1: return false;
                case  2: return change_value(key,wuint< 2>(raw_value));
                case  3: return change_value(key,wuint< 3>(raw_value));
                case  4: return change_value(key,wuint< 4>(raw_value));
                case  5: return change_value(key,wuint< 5>(raw_value));
                case  6: return change_value(key,wuint< 6>(raw_value));
                case  7: return change_value(key,wuint< 7>(raw_value));
                case  8: return change_value(key,wuint< 8>(raw_value));
                case  9: return change_value(key,wuint< 9>(raw_value));
                case 10: return change_value(key,wuint<10>(raw_value));
                case 11: return change_value(key,wuint<11>(raw_value));
                case 12: return change_value(key,wuint<12>(raw_value));
                case 13: return change_value(key,wuint<13>(raw_value));
                case 14: return change_value(key,wuint<14>(raw_value));
                case 15: return change_value(key,wuint<15>(raw_value));
                case 16: return change_value(key,wuint<16>(raw_value));
                case 17: return change_value(key,wuint<17>(raw_value));
                case 18: return change_value(key,wuint<18>(raw_value));
                case 19: return change_value(key,wuint<19>(raw_value));
                case 20: return change_value(key,wuint<20>(raw_value));
                case 21: return change_value(key,wuint<21>(raw_value));
                case 22: return change_value(key,wuint<22>(raw_value));
                case 23: return change_value(key,wuint<23>(raw_value));
                case 24: return change_value(key,wuint<24>(raw_value));
                case 25: return change_value(key,wuint<25>(raw_value));
                case 26: return change_value(key,wuint<26>(raw_value));
                case 27: return change_value(key,wuint<27>(raw_value));
                case 28: return change_value(key,wuint<28>(raw_value));
                case 29: return change_value(key,wuint<29>(raw_value));
                case 30: return change_value(key,wuint<30>(raw_value));
                case 31: return change_value(key,wuint<31>(raw_value));
                case 32: return change_value(key,wuint<32>(raw_value));
                case 33: return change_value(key,wuint<33>(raw_value));
                case 34: return change_value(key,wuint<34>(raw_value));
                case 35: return change_value(key,wuint<35>(raw_value));
                case 36: return change_value(key,wuint<36>(raw_value));
                case 37: return change_value(key,wuint<37>(raw_value));
                case 38: return change_value(key,wuint<38>(raw_value));
                case 39: return change_value(key,wuint<39>(raw_value));
                case 40: return change_value(key,wuint<40>(raw_value));
                case 41: return change_value(key,wuint<41>(raw_value));
                case 42: return change_value(key,wuint<42>(raw_value));
                case 43: return change_value(key,wuint<43>(raw_value));
                case 44: return change_value(key,wuint<44>(raw_value));
                case 45: return change_value(key,wuint<45>(raw_value));
                case 46: return change_value(key,wuint<46>(raw_value));
                case 47: return change_value(key,wuint<47>(raw_value));
                case 48: return change_value(key,wuint<48>(raw_value));
                case 49: return change_value(key,wuint<49>(raw_value));
                case 50: return change_value(key,wuint<50>(raw_value));
                case 51: return change_value(key,wuint<51>(raw_value));
                case 52: return change_value(key,wuint<52>(raw_value));
                case 53: return change_value(key,wuint<53>(raw_value));
                case 54: return change_value(key,wuint<54>(raw_value));
                case 55: return change_value(key,wuint<55>(raw_value));
                case 56: return change_value(key,wuint<56>(raw_value));
                case 57: return change_value(key,wuint<57>(raw_value));
                case 58: return change_value(key,wuint<58>(raw_value));
                case 59: return change_value(key,wuint<59>(raw_value));
                case 60: return change_value(key,wuint<60>(raw_value));
                case 61: return change_value(key,wuint<61>(raw_value));
                case 62: return change_value(key,wuint<62>(raw_value));
                case 63: return change_value(key,wuint<63>(raw_value));
                default : return false;
            } // end case
        } // end if
        else {
            return this->create_variable(key,base,raw_value);
        }
    } // end of method or member function

    std::string wuintvariant_varlist::to_string(const key_type& key) const {

        if (exists_variable(key)) {
            const auto index{get_variable(key).index()};
            switch(index) {
                case  0 : return "Strange : variable type of radix 0 can not exists";
                case  1 : return "Strange : variable type of radix 1 is not implemented";
                case  2 : return std::get< 2>(get_variable(key)).to_string();
                case  3 : return std::get< 3>(get_variable(key)).to_string();
                case  4 : return std::get< 4>(get_variable(key)).to_string();
                case  5 : return std::get< 5>(get_variable(key)).to_string();
                case  6 : return std::get< 6>(get_variable(key)).to_string();
                case  7 : return std::get< 7>(get_variable(key)).to_string();
                case  8 : return std::get< 8>(get_variable(key)).to_string();
                case  9 : return std::get< 9>(get_variable(key)).to_string();
                case 10 : return std::get<10>(get_variable(key)).to_string();
                case 11 : return std::get<11>(get_variable(key)).to_string();
                case 12 : return std::get<12>(get_variable(key)).to_string();
                case 13 : return std::get<13>(get_variable(key)).to_string();
                case 14 : return std::get<14>(get_variable(key)).to_string();
                case 15 : return std::get<15>(get_variable(key)).to_string();
                case 16 : return std::get<16>(get_variable(key)).to_string();
                case 17 : return std::get<17>(get_variable(key)).to_string();
                case 18 : return std::get<18>(get_variable(key)).to_string();
                case 19 : return std::get<19>(get_variable(key)).to_string();
                case 20 : return std::get<20>(get_variable(key)).to_string();
                case 21 : return std::get<21>(get_variable(key)).to_string();
                case 22 : return std::get<22>(get_variable(key)).to_string();
                case 23 : return std::get<23>(get_variable(key)).to_string();
                case 24 : return std::get<24>(get_variable(key)).to_string();
                case 25 : return std::get<25>(get_variable(key)).to_string();
                case 26 : return std::get<26>(get_variable(key)).to_string();
                case 27 : return std::get<27>(get_variable(key)).to_string();
                case 28 : return std::get<28>(get_variable(key)).to_string();
                case 29 : return std::get<29>(get_variable(key)).to_string();
                case 30 : return std::get<30>(get_variable(key)).to_string();
                case 31 : return std::get<31>(get_variable(key)).to_string();
                case 32 : return std::get<32>(get_variable(key)).to_string();
                case 33 : return std::get<33>(get_variable(key)).to_string();
                case 34 : return std::get<34>(get_variable(key)).to_string();
                case 35 : return std::get<35>(get_variable(key)).to_string();
                case 36 : return std::get<32>(get_variable(key)).to_string();
                case 37 : return std::get<33>(get_variable(key)).to_string();
                case 38 : return std::get<34>(get_variable(key)).to_string();
                case 39 : return std::get<35>(get_variable(key)).to_string();
                case 40 : return std::get<40>(get_variable(key)).to_string();
                case 41 : return std::get<41>(get_variable(key)).to_string();
                case 42 : return std::get<42>(get_variable(key)).to_string();
                case 43 : return std::get<43>(get_variable(key)).to_string();
                case 44 : return std::get<44>(get_variable(key)).to_string();
                case 45 : return std::get<45>(get_variable(key)).to_string();
                case 46 : return std::get<46>(get_variable(key)).to_string();
                case 47 : return std::get<47>(get_variable(key)).to_string();
                case 48 : return std::get<48>(get_variable(key)).to_string();
                case 49 : return std::get<49>(get_variable(key)).to_string();
                case 50 : return std::get<50>(get_variable(key)).to_string();
                case 51 : return std::get<51>(get_variable(key)).to_string();
                case 52 : return std::get<52>(get_variable(key)).to_string();
                case 53 : return std::get<53>(get_variable(key)).to_string();
                case 54 : return std::get<54>(get_variable(key)).to_string();
                case 55 : return std::get<55>(get_variable(key)).to_string();
                case 56 : return std::get<56>(get_variable(key)).to_string();
                case 57 : return std::get<57>(get_variable(key)).to_string();
                case 58 : return std::get<58>(get_variable(key)).to_string();
                case 59 : return std::get<59>(get_variable(key)).to_string();
                case 60 : return std::get<60>(get_variable(key)).to_string();
                case 61 : return std::get<61>(get_variable(key)).to_string();
                case 62 : return std::get<62>(get_variable(key)).to_string();
                case 63 : return std::get<63>(get_variable(key)).to_string();
                default : return "Variable of type "
                                 + std::to_string(index)
                                 + " is not implemented in this list.";
            }
        }
        else {
            return ("It do not exits a variable with name \""+key+"\"");
        }
    } // end of method or member function
} // experimentsWithVariant
