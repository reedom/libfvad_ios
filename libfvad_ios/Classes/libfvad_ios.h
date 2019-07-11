//
//  libfvad_ios.h
//  libfvad_ios
//
//  Created by HANAI Tohru on 2019/07/11.
//  Copyright © 2019 reedom. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for libfvad_ios.
FOUNDATION_EXPORT double libfvad_iosVersionNumber;

//! Project version string for libfvad_ios.
FOUNDATION_EXPORT const unsigned char libfvad_iosVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <libfvad_ios/PublicHeader.h>


/*
 * Type for a VAD instance, an opaque object created using fvad_new().
 */
typedef struct Fvad Fvad;

/*
 * Creates and initializes a VAD instance.
 *
 * On success, returns a pointer to the new VAD instance, which should
 * eventually be deleted using fvad_free().
 *
 * Returns NULL in case of a memory allocation error.
 */
FOUNDATION_EXPORT Fvad *fvad_new();

/*
 * Frees the dynamic memory of a specified VAD instance.
 */
FOUNDATION_EXPORT void fvad_free(Fvad *inst);


/*
 * Reinitializes a VAD instance, clearing all state and resetting mode and
 * sample rate to defaults.
 */
FOUNDATION_EXPORT void fvad_reset(Fvad *inst);


/*
 * Changes the VAD operating ("aggressiveness") mode of a VAD instance.
 *
 * A more aggressive (higher mode) VAD is more restrictive in reporting speech.
 * Put in other words the probability of being speech when the VAD returns 1 is
 * increased with increasing mode. As a consequence also the missed detection
 * rate goes up.
 *
 * Valid modes are 0 ("quality"), 1 ("low bitrate"), 2 ("aggressive"), and 3
 * ("very aggressive"). The default mode is 0.
 *
 * Returns 0 on success, or -1 if the specified mode is invalid.
 */
FOUNDATION_EXPORT int fvad_set_mode(Fvad* inst, int mode);


/*
 * Sets the input sample rate in Hz for a VAD instance.
 *
 * Valid values are 8000, 16000, 32000 and 48000. The default is 8000. Note
 * that internally all processing will be done 8000 Hz; input data in higher
 * sample rates will just be downsampled first.
 *
 * Returns 0 on success, or -1 if the passed value is invalid.
 */
FOUNDATION_EXPORT int fvad_set_sample_rate(Fvad* inst, int sample_rate);


/*
 * Calculates a VAD decision for an audio frame.
 *
 * `frame` is an array of `length` signed 16-bit samples. Only frames with a
 * length of 10, 20 or 30 ms are supported, so for example at 8 kHz, `length`
 * must be either 80, 160 or 240.
 *
 * Returns              : 1 - (active voice),
 *                        0 - (non-active Voice),
 *                       -1 - (invalid frame length).
 */
FOUNDATION_EXPORT int fvad_process(Fvad* inst, const int16_t* frame, size_t length);

