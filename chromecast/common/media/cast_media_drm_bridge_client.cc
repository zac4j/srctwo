// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chromecast/common/media/cast_media_drm_bridge_client.h"

#include "chromecast/media/base/key_systems_common.h"

namespace chromecast {
namespace media {

CastMediaDrmBridgeClient::CastMediaDrmBridgeClient() {}

CastMediaDrmBridgeClient::~CastMediaDrmBridgeClient() {}

void CastMediaDrmBridgeClient::AddKeySystemUUIDMappings(KeySystemUuidMap* map) {
// Note: MediaDrmBridge adds the Widevine UUID mapping automatically.
#if defined(PLAYREADY_CDM_AVAILABLE)
  (*map)[kChromecastPlayreadyKeySystem] = playready_delegate_.GetUUID();
#endif
}

::media::MediaDrmBridgeDelegate*
CastMediaDrmBridgeClient::GetMediaDrmBridgeDelegate(
    const ::media::UUID& scheme_uuid) {
#if defined(PLAYREADY_CDM_AVAILABLE)
  if (scheme_uuid == playready_delegate_.GetUUID())
    return &playready_delegate_;
#endif

  if (scheme_uuid == widevine_delegate_.GetUUID())
    return &widevine_delegate_;

  return nullptr;
}

}  // namespace media
}  // namespace chromecast
