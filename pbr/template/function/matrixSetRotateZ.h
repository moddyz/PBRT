#pragma once

#include <pbr/api.h>

{% for matrixType in context.types -%}
#include <pbr/type/{{ matrixType.headerFileName }}>
{% endfor %}

#include <pbr/function/degreesToRadians.h>

/// Sets a Z-axis rotate transformation on a matrix.

PBR_NAMESPACE_BEGIN

{% for matrixType in context.types %}
PBR_API
inline void FnMatrixSetRotateZ( const {{ matrixType.elementType.className }}& i_degrees, {{ matrixType.className }}& o_matrix )
{
    {{ matrixType.elementType.className }} radians;
    FnDegreesToRadians( i_degrees, radians );
    {{ matrixType.elementType.className }} sine = std::sin( radians );
    {{ matrixType.elementType.className }} cosine = std::cos( radians );
    o_matrix( 0, 0 ) = cosine;
    o_matrix( 0, 1 ) = -sine;
    o_matrix( 1, 0 ) = sine;
    o_matrix( 1, 1 ) = cosine;
}
{% endfor %}

PBR_NAMESPACE_END
