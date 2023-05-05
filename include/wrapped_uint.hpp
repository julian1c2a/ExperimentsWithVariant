#ifndef EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP
#define EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP

#include <limits>
#include <utility>
#include <type_traits>
#include <string>
#include <iostream>
#include <concepts>

namespace experimentsWithVariant {


template<unsigned int N> class wrapped_uint {

    unsigned int m_value{};

    template<std::integral Int_t>
    static inline constexpr unsigned int normalize(Int_t intarg) noexcept {
        if constexpr (std::is_unsigned_v<Int_t>) {
            if constexpr (std::is_same_v<Int_t,unsigned int>) {
                return static_cast<unsigned int>(intarg % N);
            }
            else if constexpr (sizeof(Int_t) > sizeof(unsigned int)) {
                return static_cast<unsigned int>(intarg % static_cast<Int_t>(N));
            }
            else {
                if constexpr (std::numeric_limits<Int_t>::max() < N-1) {
                    return static_cast<unsigned int>(intarg);
                }
                else {
                    return static_cast<unsigned int>(
                        intarg % static_cast<Int_t>(N)
                    );
                }
            }
        }
        else {
            if constexpr (sizeof(Int_t) >= 2*sizeof(unsigned int)) {
                if (intarg < 0) {
                    const Int_t absintarg{std::abs(intarg)};
                    const Int_t norm_absintarg{absintarg%static_cast<Int_t>(N)};
                    const Int_t norm_intarg{
                        static_cast<Int_t>(N)-norm_absintarg
                    };
                    return static_cast<unsigned int>(norm_intarg);
                }
                else {
                    return static_cast<unsigned int>(
                        intarg%static_cast<Int_t>(N)
                    );
                }
            }
            else {
                if constexpr (std::numeric_limits<Int_t>::max() < N-1) {
                    if (intarg >= 0)
                        return static_cast<unsigned int>(intarg);
                    else
                        return (N-static_cast<unsigned int>(intarg));
                }
                else {
                    if (intarg < 0) {
                        const unsigned int absintarg{
                            (intarg < 0)?(-intarg):(intarg)
                        };
                        const unsigned int norm_absintarg{absintarg%N};
                        const unsigned int norm_intarg{N-norm_absintarg};
                        return (norm_intarg);
                    }
                    else {
                        return (static_cast<unsigned int>(intarg)%N);
                    }
                }
            }
        }
    }

public:

    template<std::integral Int_t>
    explicit operator Int_t() const {
        if constexpr (std::is_integral<Int_t>::value) {
            return static_cast<Int_t>(m_value);
        } else {
            throw std::runtime_error(
                "wrapped_uint<N>::operator Int_t<Int_t>() const: \
                 wrong type, the type must be a integral type"
            );
        }
    }

    constexpr wrapped_uint() noexcept = default;

    template<std::integral Int_t>
    explicit constexpr wrapped_uint(Int_t value) noexcept :
        m_value{normalize(value)} {}

    constexpr wrapped_uint(const wrapped_uint &) noexcept = default;

    constexpr wrapped_uint(wrapped_uint &&) noexcept = default;

    constexpr wrapped_uint &operator=(const wrapped_uint &) noexcept = default;

    constexpr wrapped_uint &operator=(wrapped_uint &&) noexcept = default;

    template<std::integral Int_t>
    constexpr wrapped_uint & operator=(unsigned int value) noexcept {
        m_value = normalize(value);
        return (*this);
    }

    template<std::integral Int_t>
    Int_t operator()() noexcept
    { return static_cast<Int_t>(m_value); }

    const wrapped_uint& operator++() noexcept {
        if ( m_value < ( N - 1 )) {
            ++m_value;
        } else {
            m_value = 0;
        }
        return (*this);
    }

    const wrapped_uint &operator--() noexcept {
        if (m_value > 0) {
            --m_value;
        } else {
            m_value = (N - 1);
        }
        return *this;
    }

    wrapped_uint operator++(int) noexcept {
        wrapped_uint result{m_value};
        ++(*this);
        return std::move(result);
    }

    wrapped_uint operator--(int) noexcept {
        wrapped_uint result{m_value};
        --(*this);
        return std::move(result);
    }

    wrapped_uint complRadix() const noexcept {
        unsigned int result{0};
        if (m_value != 0)
            result = (N - m_value);
        return wrapped_uint{result};
    }

    wrapped_uint modComplRadix() noexcept {
        if (m_value != 0) {
            m_value = (N - m_value);
        } else {
            m_value = 0;
        }
        return {*this};
    }

    wrapped_uint complRadixMinus1() const noexcept {
        return wrapped_uint{N - 1 - m_value};
    }

    wrapped_uint modComplRadixMinus1() noexcept {
        m_value = N - 1 - m_value;
        return {*this};
    }

    wrapped_uint &operator+=(wrapped_uint n) noexcept {
        const unsigned int compl_n_m_value{N - n.m_value};
        if (m_value >= compl_n_m_value) {
            m_value -= compl_n_m_value;
        } else {
            m_value += n.m_value;
        }
        return (*this);
    }

    wrapped_uint &operator-=(wrapped_uint n) noexcept {
        if (m_value >= n.m_value) {
            m_value -= n.m_value;
        }
        else {
            m_value += (N - n.m_value);
        }
        return (*this);
    }

    const wrapped_uint& operator+() const noexcept {
        return {*this};
    }

    wrapped_uint operator-() const noexcept {
        return ((*this).complRadix());
    }

    wrapped_uint operator~() const noexcept {
        return ((*this).complRadixMinus1());
    }

    bool operator==(wrapped_uint n) const noexcept {
        return (m_value == n.m_value);
    }

    bool operator!=(wrapped_uint n) const noexcept {
        return (m_value != n.m_value);
    }

    bool operator<(wrapped_uint n) const noexcept {
        return (m_value < n.m_value);
    }

    bool operator<=(wrapped_uint n) const noexcept {
        return (m_value <= n.m_value);
    }

    bool operator>(wrapped_uint n) const noexcept {
        return (m_value > n.m_value);
    }

    bool operator>=(wrapped_uint n) const noexcept {
        return (m_value >= n.m_value);
    }

    bool operator==(unsigned int n) const noexcept {
        return (m_value == (n % N));
    }

    bool operator!=(unsigned int n) const noexcept {
        return (m_value != (n % N));
    }

    bool operator<(unsigned int n) const noexcept {
        return (m_value < (n % N));
    }

    bool operator<=(unsigned int n) const noexcept {
        return (m_value <= (n % N));
    }

    bool operator>(unsigned int n) const noexcept {
        return (m_value > (n % N));
    }

    bool operator>=(unsigned int n) const noexcept {
        return (m_value >= (n % N));
    }

    [[nodiscard]] std::string to_string() const noexcept {
        std::string result;
        result += "dig#";
        result += std::to_string(m_value);
        result += "#B";
        result += std::to_string(N);
        return result;
    }

    static void from_string(const std::string& strarg,wrapped_uint& target) {
        std::size_t pos{0};
        while(strarg[pos]==' ' || strarg[pos]=='\t') {
            ++pos;
        }
        std::string first_token;
        const bool b0{strarg[pos]=='d'};
        first_token += strarg[pos];
        ++pos;
        const bool b1{strarg[pos]=='i'};
        first_token += strarg[pos];
        ++pos;
        const bool b2{strarg[pos]=='g'};
        first_token += strarg[pos];
        ++pos;
        const bool b3{strarg[pos]=='#'};
        first_token += strarg[pos];
        ++pos;
        bool b6{false};
        while(strarg[pos]==' ' || strarg[pos]=='\t') {
            ++pos;
        }
        unsigned long long int intin{0};
        while(strarg[pos]>= '0' && strarg[pos]<='9') {
            b6 = true;
            intin *= 10;
            intin += (strarg[pos] - '0');
            ++pos;
        }
        while(strarg[pos]==' ' || strarg[pos]=='\t') {
            ++pos;
        }
        std::string second_token;
        const bool b4{strarg[pos]=='#'};
        second_token += strarg[pos];
        ++pos;
        const bool b5{strarg[pos]=='B'};
        second_token += strarg[pos];
        ++pos;
        while(strarg[pos]==' ' || strarg[pos]=='\t') {
            ++pos;
        }
        bool b7{false};
        unsigned int base{0};
        while(strarg[pos]>= '0' && strarg[pos]<='9') {
            b7 = true;
            base *= 10;
            base += (strarg[pos] - '0');
            ++pos;
        }

        if(b0 && b1 && b2 && b3 && b4 && b5 && b6 && b7) {
            if (base == N) {
                target.m_value = intin % base;
            }
            else {
                throw std::invalid_argument(
                    "Invalid base : your base is "
                    + std::to_string(base)
                    + " but base must be "
                    + std::to_string(N)
                );
        }
    }
    else {
        if (!b0 || !b1 || !b2 || !b3) {
            throw std::invalid_argument(
                "Invalid format: we have "
                + first_token
                + " it must be \"dig#\""
            );
        }
        else if (!b6) {
            throw std::invalid_argument(
                "Invalid argument: You have not written a value for wrapped_int"
            );
        }
        else if (!b4 || !b5) {
            throw std::invalid_argument(
                "Invalid format: we have "
                + second_token
                + " it must be \"#B\""
            );
        }
        else {
            throw std::invalid_argument(
                "Invalid argument: You have not written a value for the \
                 Radix argument of wrapped_int"
            );
        }
    }
}

friend std::ostream &operator<<(std::ostream &os, const wrapped_uint &n) {
    os << n.to_string();
    return os;
}

friend std::istream &operator>>(std::istream &is,wrapped_uint &n) {
    std::string str_in_to_parse;
    is >> str_in_to_parse;
    from_string(str_in_to_parse,n);
    return is;
}

};// end template class wrapped_uint
} // namespace experimentsWithVariant
#endif //EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP
