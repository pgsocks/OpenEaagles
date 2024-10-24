
#ifndef __oe_base_Yiq_H__
#define __oe_base_Yiq_H__

#include "openeaagles/base/Color.hpp"

namespace oe {
namespace base {

//------------------------------------------------------------------------------
// Class:  Yiq
//
// Description:  Defines a YIQ color as used in NTSC
//
// Y defines the luminance, for a black-and-white image.
// I and Q determine the color.
//
// Factory name: yiq
// Slots:
//       Y  <Number>  Y component (0.0 to 1.0) (default: 0.0)
//       I  <Number>  I component (-0.6 to 0.6) (default: 0.0)
//       Q  <Number>  Q component (-0.52.0 to 0.52) (default: 0.0)
//
// Events: None
//
//
// Public methods: Base class public methods, plus ...
//
//      Yiq(const double y, const double i, const double q)
//          Special constructor that initializes the object to y, i, and q
//
//      double y()
//      double i()
//      double q()
//          Data access routines.  Returns the individual YIQ components.
//
//      getYIQ(Vec3d yiq)
//          Returns the YIQ components in a vector.
//
//      static void yiq2rgb(Vec4d& rgb, const Vec3d& yiq);
//      static void rgb2yiq(Vec3d& yiq, const Vec4d& rgb);
//          Static functions to convert YIQ colors to RGB and visa versa.
//
// Enumerated:
//      { Y, I, Q }
//          Used to index the YIQ color vectors.
//
//
// Note:  The operators Vec3d*() and Vec4d*(), (inherited from Color)
//        return a const pointer to the RGBA color vector and not the
//        YIQ color vector.
//------------------------------------------------------------------------------
class Yiq : public Color
{
    DECLARE_SUBCLASS(Yiq, Color)

public:
    // components of YIQ color
    enum { Y, I, Q };

public:
    Yiq(const double y, const double i, const double q);
    Yiq();

    double y() const;
    double i() const;
    double q() const;
    void getYIQ(Vec3d& yiq) const;

    virtual bool setY(Number* const msg);
    virtual bool setI(Number* const msg);
    virtual bool setQ(Number* const msg);

    static void yiq2rgb(Vec4d& rgb, const Vec3d& yiq);
    static void rgb2yiq(Vec3d& yiq, const Vec4d& rgb);

protected:
    Vec3d yiq;
};

}
}

#endif
