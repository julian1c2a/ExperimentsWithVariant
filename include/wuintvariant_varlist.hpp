//
// Created by Julian Calderon Almendros on 04/05/2023.
//

#ifndef GUARD_EXPERIMENTSWITHVARIANT_WUINTVARIANT_VARLIST_HPP
#define GUARD_EXPERIMENTSWITHVARIANT_WUINTVARIANT_VARLIST_HPP

#include <variant>
#include <map>
#include <string>
#include <type_traits>
#include <utility>
#include "variant_type.hpp"

namespace experiments_with_variant {

    class [[maybe_unused]] wuintvariant_varlist {
    public:
        using key_type = typename std::string;
        using value_type = typename experiments_with_variant::wrapped_uint_variant;
        using node_type [[maybe_unused]] = typename std::pair<key_type,value_type>;
        using map = typename std::map<key_type,value_type>;
        using uint_type = unsigned int;
    private:
        map m_list{};
        uint_type m_count{};
        const uint_type m_max_size{};
    public:
        wuintvariant_varlist() noexcept : m_max_size(128u),m_count(0u) { m_list.clear(); }
        constexpr wuintvariant_varlist(const wuintvariant_varlist&) noexcept = delete;
        constexpr wuintvariant_varlist(wuintvariant_varlist&&) noexcept = delete;
        constexpr wuintvariant_varlist& operator=(const wuintvariant_varlist&) noexcept = delete;
        constexpr wuintvariant_varlist& operator=(wuintvariant_varlist&&) noexcept = delete;

        [[maybe_unused]] bool create_variable(const key_type& key, const value_type& value) noexcept;
        [[maybe_unused]] bool create_variable(const node_type& node) noexcept;
        bool create_variable(const key_type& key, uint_type constintvalue, uint_type raw_value) noexcept;
        [[maybe_unused]] bool erase_variable(const key_type& key) noexcept;
        bool change_value(const key_type& key, const value_type& value) noexcept;
        value_type get_variable(const key_type& key) const noexcept;
        bool exists_variable(const key_type& key) const noexcept;
    };

} // namespace experiments_with_variant

#endif //GUARD_EXPERIMENTSWITHVARIANT_WUINTVARIANT_VARLIST_HPP
