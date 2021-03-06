// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGN_PROMO_VIEW_DELEGATE_H_
#define IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGN_PROMO_VIEW_DELEGATE_H_

#import <UIKit/UIKit.h>

@class SigninPromoView;

@protocol SigninPromoViewDelegate<NSObject>

// Called by SigninPromoView when the user taps the primary button in cold state
// mode.
- (void)signinPromoViewDidTapSigninWithNewAccount:(SigninPromoView*)view;

// Called by SigninPromoView when the user taps the primary button in warm state
// mode.
- (void)signinPromoViewDidTapSigninWithDefaultAccount:(SigninPromoView*)view;

// Called by SigninPromoView when the user taps the secondary button in warm
// state mode.
- (void)signinPromoViewDidTapSigninWithOtherAccount:(SigninPromoView*)view;

@end

#endif  // IOS_CHROME_BROWSER_UI_AUTHENTICATION_SIGN_PROMO_VIEW_DELEGATE_H_
