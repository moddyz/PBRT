#pragma once

#include <cmath>
#include <pbr/tools/assert.h>

namespace pbr
{
class Matrix3f
{
public:
    explicit Matrix3f( const float& i_element0,
                       const float& i_element1,
                       const float& i_element2,
                       const float& i_element3,
                       const float& i_element4,
                       const float& i_element5,
                       const float& i_element6,
                       const float& i_element7,
                       const float& i_element8 )
        : m_elements{i_element0,
                     i_element1,
                     i_element2,
                     i_element3,
                     i_element4,
                     i_element5,
                     i_element6,
                     i_element7,
                     i_element8}
    {
        PBR_ASSERT( !HasNans() );
    }

    float& operator[]( size_t i_index )
    {
        return m_elements[ i_index ];
    }

    const float& operator[]( size_t i_index ) const
    {
        return m_elements[ i_index ];
    }

    bool HasNans() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] ) || std::isnan( m_elements[ 4 ] ) || std::isnan( m_elements[ 5 ] ) ||
               std::isnan( m_elements[ 6 ] ) || std::isnan( m_elements[ 7 ] ) || std::isnan( m_elements[ 8 ] );
    }

private:
    float m_elements[ 9 ] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
};
} // namespace pbr