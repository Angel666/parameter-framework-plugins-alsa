/*
 * Copyright (c) 2011-2014, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include "FormattedSubsystemObject.h"
#include <stdint.h>

/**
 * Alsa subsystem object class.
 * This class handles an alsa card, this is the base class for all alsa parameters.
 */
class AlsaSubsystemObject : public CFormattedSubsystemObject
{
public:
    AlsaSubsystemObject(const string &mappingValue,
                        CInstanceConfigurableElement *instanceConfigurableElement,
                        const CMappingContext &context);
    AlsaSubsystemObject(const string &strMappingValue,
                        CInstanceConfigurableElement *instanceConfigurableElement,
                        uint32_t firstAmendKey,
                        uint32_t nbAmendKeys,
                        const CMappingContext &context);

protected:
    /**
     * Get card number
     *
     * @return the number of the alsa card
     */
    int32_t getCardNumber() const { return _cardIndex; }

    /**
     * Get card name
     *
     * @return the name of the alsa card
     */
    const string &getCardName() const { return _cardName; }

private:
    /**
     * This function return the card number associated with the card ID (name) passed as argument
     *
     * @param[in] cardName an alsa card name
     *
     * @return the number of the corresponding alsa card
     */
    static int getCardNumberByName(const string &cardName);

    /** Path of the sound card in the file system */
    static const char _soundCardPath[];
    /** Card name to which the Alsa device belong */
    string _cardName;
    /** Card Index to which the Alsa device belong */
    int32_t _cardIndex;
};
