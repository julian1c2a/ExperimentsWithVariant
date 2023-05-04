#ifndef GUARD_EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP_
#define GUARD_EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP_

#include <utility>
#include <type_traits>
#include <string>
#include <iostream>
#include <concepts>

namespace experiments_with_variant {


    template<unsigned int N> requires (N > 1)
    class wrapped_uint {
        unsigned int m_value{};

    public:

        template<std::integral Int_t>
        explicit operator Int_t() const {
            return static_cast<Int_t>(m_value);
        }

        constexpr wrapped_uint() noexcept = default;

        explicit constexpr wrapped_uint(unsigned int n) noexcept : m_value(n % N) {}

        constexpr wrapped_uint(const wrapped_uint &n) noexcept = default;

        constexpr wrapped_uint(wrapped_uint &&n) noexcept = default;

        constexpr wrapped_uint &operator=(const wrapped_uint &n) noexcept = default;

        constexpr wrapped_uint &operator=(wrapped_uint &&n) noexcept = default;

        constexpr wrapped_uint &operator=(unsigned int n) noexcept {
            m_value = n % N;
            return (*this);
        }

        unsigned int operator()() noexcept { return (m_value); }

        const wrapped_uint &operator++() noexcept {
            if (m_value < N - 1) {
                ++m_value;
            } else {
                m_value = 0;
            }
            return *this;
        }

        const wrapped_uint &operator--() noexcept {
            if (m_value > 0) {
                --m_value;
            } else {
                m_value = N - 1;
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

        [[maybe_unused]] wrapped_uint complN() const noexcept {
            if (m_value != 0)
                return wrapped_uint{N - m_value};
            else
                return wrapped_uint{};
        }

        [[maybe_unused]] wrapped_uint modComplN() noexcept {
            if (m_value != 0) {
                m_value = N - m_value;
                return {*this};
            } else {
                m_value = 0;
                return {*this};
            }
        }

        [[maybe_unused]] wrapped_uint complNm1() const noexcept {
            return wrapped_uint{N - m_value};
        }

        [[maybe_unused]] wrapped_uint modComplNm1() noexcept {
            m_value = N - m_value;
            return {*this};
        }

        wrapped_uint &operator+=(wrapped_uint n) noexcept {
            if (m_value >= N - n.m_value) {
                m_value -= (N - n.m_value);
            } else {
                m_value += n.m_value;
            }
            return (*this);
        }

        wrapped_uint &operator-=(wrapped_uint n) noexcept {
            if (m_value >= n.m_value) {
                m_value -= n.m_value;
            } else {
                m_value += (N - n.m_value);
            }
            return (*this);
        }

        wrapped_uint operator+() const noexcept {
            return {*this};
        }

        wrapped_uint operator-() const noexcept {
            return ((*this).complN());
        }

        wrapped_uint operator~() const noexcept {
            return ((*this).complNm1());
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

        friend std::ostream &operator<<(std::ostream &os, const wrapped_uint &n) {
            os << n.to_string();
            return os;
        }

    };
} // namespace experiments_with_variant
#endif //GUARD_EXPERIMENTSWITHVARIANT_WRAPPED_UINT_HPP_
