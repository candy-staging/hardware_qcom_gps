/* Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation, nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <LocationUtil.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V1_0 {
namespace implementation {

void convertGnssLocation(Location& in, GnssLocation& out)
{
    memset(&out, 0, sizeof(GnssLocation));
    if (in.flags & LOCATION_HAS_LAT_LONG_BIT)
        out.gnssLocationFlags |= GnssLocationFlags::HAS_LAT_LONG;
    if (in.flags & LOCATION_HAS_ALTITUDE_BIT)
        out.gnssLocationFlags |= GnssLocationFlags::HAS_ALTITUDE;
    if (in.flags & LOCATION_HAS_SPEED_BIT)
        out.gnssLocationFlags |= GnssLocationFlags::HAS_SPEED;
    if (in.flags & LOCATION_HAS_BEARING_BIT)
        out.gnssLocationFlags |= GnssLocationFlags::HAS_BEARING;
    if (in.flags & LOCATION_HAS_ACCURACY_BIT) {
        out.gnssLocationFlags |= GnssLocationFlags::HAS_HORIZONTAL_ACCURACY;
        //out.gnssLocationFlags |= GnssLocationFlags::HAS_VERTICAL_ACCURACY;
        //out.gnssLocationFlags |= GnssLocationFlags::HAS_SPEED_ACCURACY;
        //out.gnssLocationFlags |= GnssLocationFlags::HAS_BEARING_ACCURACY;
    }
    out.latitudeDegrees = in.latitude;
    out.longitudeDegrees = in.longitude;
    out.altitudeMeters = in.altitude;
    out.speedMetersPerSec = in.speed;
    out.bearingDegrees = in.bearing;
    out.horizontalAccuracyMeters = in.accuracy;
    //out.verticalAccuracyMeters = in.accuracy;
    //out.speedAccuracyMetersPerSecond = in.accuracy;
    //out.bearingAccuracyDegrees = in.accuracy;
    out.timestamp = static_cast<GnssUtcTime>(in.timestamp);
}

void convertGnssConstellationType(GnssSvType& in, GnssConstellationType& out)
{
    switch(in) {
        case GNSS_SV_TYPE_GPS:
            out = GnssConstellationType::UNKNOWN;
            break;
        case GNSS_SV_TYPE_SBAS:
            out = GnssConstellationType::SBAS;
            break;
        case GNSS_SV_TYPE_GLONASS:
            out = GnssConstellationType::GLONASS;
            break;
        case GNSS_SV_TYPE_QZSS:
            out = GnssConstellationType::QZSS;
            break;
        case GNSS_SV_TYPE_BEIDOU:
            out = GnssConstellationType::BEIDOU;
            break;
        case GNSS_SV_TYPE_GALILEO:
            out = GnssConstellationType::GALILEO;
            break;
        default:
            out = GnssConstellationType::UNKNOWN;
            break;
    }
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android
