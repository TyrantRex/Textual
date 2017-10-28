/* ********************************************************************* 
                  _____         _               _
                 |_   _|____  _| |_ _   _  __ _| |
                   | |/ _ \ \/ / __| | | |/ _` | |
                   | |  __/>  <| |_| |_| | (_| | |
                   |_|\___/_/\_\\__|\__,_|\__,_|_|

 Copyright (c) 2010 - 2017 Codeux Software, LLC & respective contributors.
        Please see Acknowledgements.pdf for additional information.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Textual and/or "Codeux Software, LLC", nor the 
      names of its contributors may be used to endorse or promote products 
      derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

 *********************************************************************** */

#import "ICLInlineContentModule.h"

NS_ASSUME_NONNULL_BEGIN

/* ICMInlineVideoFoundation does nothing.
 It exists for internal use. */
@interface ICMInlineVideoFoundation : ICLInlineContentModule
@property (nonatomic, assign) BOOL videoAutoplayEnabled; // default = NO
@property (nonatomic, assign) BOOL videoControlsEnabled; // default = YES
@property (nonatomic, assign) BOOL videoLoopEnabled; // default = NO
@property (nonatomic, assign) BOOL videoMuteEnabled; // default = NO
@property (nonatomic, assign) NSTimeInterval videoStartTime; // default = 0
@property (nonatomic, assign) double videoPlaybackSpeed; // default = 1.0 | >= 0.125 and <= 6.0
@end

/* Proper class to sublcass if that is your thing. */
@interface ICMInlineVideo : ICMInlineVideoFoundation
- (void)performAction; // checkVideo = YES
- (void)performActionWithVideoCheck:(BOOL)checkVideo;

- (void)performActionForAddress:(NSString *)address; // bypassVideoCheck = NO
- (void)performActionForAddress:(NSString *)address bypassVideoCheck:(BOOL)bypassVideoCheck;

- (void)performActionForURL:(NSURL *)url; // bypassVideoCheck = NO
- (void)performActionForURL:(NSURL *)url bypassVideoCheck:(BOOL)bypassVideoCheck;

+ (ICLInlineContentModuleActionBlock)actionBlockForAddress:(NSString *)address; // bypassVideoCheck = NO
+ (ICLInlineContentModuleActionBlock)actionBlockForAddress:(NSString *)address bypassVideoCheck:(BOOL)bypassVideoCheck;

+ (ICLInlineContentModuleActionBlock)actionBlockForForURL:(NSURL *)url; // bypassVideoCheck = NO
+ (ICLInlineContentModuleActionBlock)actionBlockForForURL:(NSURL *)url bypassVideoCheck:(BOOL)bypassVideoCheck;

- (void)notifyUnsafeToLoadVideo;
@end

/* Subclass that can be used for videos that should be trated as such:
 videoAutoplayEnabled = YES,
 videoControlsEnabled = NO,
 videoLoopEnabled = YES,
 videoMuteEnabled = YES */
@interface ICMInlineGifVideo : ICMInlineVideo
@end

NS_ASSUME_NONNULL_END
