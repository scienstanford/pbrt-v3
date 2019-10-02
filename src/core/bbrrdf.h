//
//  bbrrdf.h
//  PBRT-V3
//  BBRRDF stands for bispectral bidirectional reflection
//  and reradiation function.
//
//  Created by ZhengLyu on 6/29/19.
//

#if defined(_MSC_VER)
#define NOMINMAX
#progama once
#endif

#ifndef PBRT_CORE_BBRRDF_H
#define PBRT_CORE_BBRRDF_H

// core/bbrrdf.h*
#include "interaction.h"
#include "reflection.h"
#include "stats.h"

namespace pbrt {

// BBRRDF Declarations
class BBRRDF {
    public:
        // BBRRDF Public Methods
        BBRRDF(PhotoLumi reRadMatrix) : reRadMatrix(reRadMatrix) {}
        virtual ~BBRRDF() {}
        virtual PhotoLumi f(const Vector3f &wo, const Vector3f &wi) const = 0;
        virtual PhotoLumi Sample_f(const Vector3f &wo, Vector3f *wi,
                           const Point2f &sample, Float *pdf, BxDFType type = BSDF_ALL,
                           BxDFType *sampledType = nullptr) const = 0;
        virtual Float Pdf(const Vector3f &wo, const Vector3f &wi) const = 0;
    
    
    protected:
        // BBRRDF Protected Data
        PhotoLumi reRadMatrix;
    
};

//class SubSurfaceBBRRDF : public BBRRDF {
//    public:
//        // SubSurfaceBBRRDF Public Methods
//        SubSurfaceBBRRDF(Eigen::MatrixXd reRadMatrix, const SurfaceInteraction &po, Float eta)
//            : BBRRDF(reRadMatrix),
//              po(po),
//              eta(eta) {}
//
//        // The functions below are temporarily used for demo, which are not true
//        PhotoLumi S(const SurfaceInteraction &pi, const Vector3f &wi) const;
//        PhotoLumi Sample_S(const Scene &scene, Float u1, const Point2f &u2,
//                                   MemoryArena &arena, SurfaceInteraction *si,
//                                   Float *pdf) const;
//
//    protected:
//        // SubSurfaceBSSRDF Protected Data
//        const SurfaceInteraction &po;
//        Float eta;
//};

class SurfaceBBRRDF : public BBRRDF {
    public:
        // SurfaceBBRRDF Public Methods
        SurfaceBBRRDF(PhotoLumi reRadMatrix)
            : BBRRDF(reRadMatrix) {}
    
        // The functions below are temporarily used for demo, which are not true
        PhotoLumi f(const Vector3f &wo, const Vector3f &wi) const;
        PhotoLumi Sample_f(const Vector3f &wo, Vector3f *wi,
                           const Point2f &sample, Float *pdf, BxDFType type = BSDF_ALL,
                           BxDFType *sampledType = nullptr) const;
        Float Pdf(const Vector3f &wo, const Vector3f &wi) const;
};

} // pbrt namespace

#endif // PBRT_CORE_BBRRDF_H
