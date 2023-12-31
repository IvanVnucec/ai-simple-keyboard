/*
 * Copyright (C) 2013, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * !!!!! DO NOT EDIT THIS FILE !!!!!
 *
 * This file was generated from
 *   dictionary/structure/v4/content/bigram_dict_content.h
 */

#ifndef LATINIME_BACKWARD_V402_BIGRAM_DICT_CONTENT_H
#define LATINIME_BACKWARD_V402_BIGRAM_DICT_CONTENT_H

#include "defines.h"
#include "dictionary/structure/backward/v402/content/bigram_entry.h"
#include "dictionary/structure/backward/v402/content/sparse_table_dict_content.h"
#include "dictionary/structure/backward/v402/content/terminal_position_lookup_table.h"
#include "dictionary/structure/backward/v402/ver4_dict_constants.h"

namespace latinime {
namespace backward {
namespace v402 {

class BigramDictContent : public SparseTableDictContent {
 public:
    BigramDictContent(const char *const dictPath, const bool hasHistoricalInfo,
            const bool isUpdatable)
            : SparseTableDictContent(dictPath,
                      Ver4DictConstants::BIGRAM_LOOKUP_TABLE_FILE_EXTENSION,
                      Ver4DictConstants::BIGRAM_CONTENT_TABLE_FILE_EXTENSION,
                      Ver4DictConstants::BIGRAM_FILE_EXTENSION, isUpdatable,
                      Ver4DictConstants::BIGRAM_ADDRESS_TABLE_BLOCK_SIZE,
                      Ver4DictConstants::BIGRAM_ADDRESS_TABLE_DATA_SIZE),
              mHasHistoricalInfo(hasHistoricalInfo) {}

    BigramDictContent(const bool hasHistoricalInfo)
            : SparseTableDictContent(Ver4DictConstants::BIGRAM_ADDRESS_TABLE_BLOCK_SIZE,
                      Ver4DictConstants::BIGRAM_ADDRESS_TABLE_DATA_SIZE),
              mHasHistoricalInfo(hasHistoricalInfo) {}

    const BigramEntry getBigramEntry(const int bigramEntryPos) const {
        int readingPos = bigramEntryPos;
        return getBigramEntryAndAdvancePosition(&readingPos);
    }

    const BigramEntry getBigramEntryAndAdvancePosition(int *const bigramEntryPos) const;

    // Returns head position of bigram list for a PtNode specified by terminalId.
    int getBigramListHeadPos(const int terminalId) const {
        const SparseTable *const addressLookupTable = getAddressLookupTable();
        if (!addressLookupTable->contains(terminalId)) {
            return NOT_A_DICT_POS;
        }
        return addressLookupTable->get(terminalId);
    }

    bool writeBigramEntryAtTail(const BigramEntry *const bigramEntryToWrite) {
        int writingPos = getContentBuffer()->getTailPosition();
        return writeBigramEntryAndAdvancePosition(bigramEntryToWrite, &writingPos);
    }

    bool writeBigramEntry(const BigramEntry *const bigramEntryToWrite, const int entryWritingPos) {
        int writingPos = entryWritingPos;
        return writeBigramEntryAndAdvancePosition(bigramEntryToWrite, &writingPos);
    }

    bool writeBigramEntryAndAdvancePosition(const BigramEntry *const bigramEntryToWrite,
            int *const entryWritingPos);

    bool createNewBigramList(const int terminalId) {
        const int bigramListPos = getContentBuffer()->getTailPosition();
        return getUpdatableAddressLookupTable()->set(terminalId, bigramListPos);
    }

    bool copyBigramList(const int bigramListPos, const int toPos, int *const outTailEntryPos);

    bool flushToFile(const char *const dictPath) const {
        return flush(dictPath, Ver4DictConstants::BIGRAM_LOOKUP_TABLE_FILE_EXTENSION,
                Ver4DictConstants::BIGRAM_CONTENT_TABLE_FILE_EXTENSION,
                Ver4DictConstants::BIGRAM_FILE_EXTENSION);
    }

    bool runGC(const TerminalPositionLookupTable::TerminalIdMap *const terminalIdMap,
            const BigramDictContent *const originalBigramDictContent,
            int *const outBigramEntryCount);

    bool isContentTailPos(const int pos) const {
        return pos == getContentBuffer()->getTailPosition();
    }

 private:
    DISALLOW_COPY_AND_ASSIGN(BigramDictContent);

    int createAndGetBigramFlags(const bool hasNext) const {
        return hasNext ? Ver4DictConstants::BIGRAM_HAS_NEXT_MASK : 0;
    }

    int getBigramEntrySize() const {
        if (mHasHistoricalInfo) {
            return Ver4DictConstants::BIGRAM_FLAGS_FIELD_SIZE
                    + Ver4DictConstants::TIME_STAMP_FIELD_SIZE
                    + Ver4DictConstants::WORD_LEVEL_FIELD_SIZE
                    + Ver4DictConstants::WORD_COUNT_FIELD_SIZE
                    + Ver4DictConstants::BIGRAM_TARGET_TERMINAL_ID_FIELD_SIZE;
        } else {
            return Ver4DictConstants::BIGRAM_FLAGS_FIELD_SIZE
                    + Ver4DictConstants::PROBABILITY_SIZE
                    + Ver4DictConstants::BIGRAM_TARGET_TERMINAL_ID_FIELD_SIZE;
        }
    }

    bool runGCBigramList(const int bigramListPos,
            const BigramDictContent *const sourceBigramDictContent, const int toPos,
            const TerminalPositionLookupTable::TerminalIdMap *const terminalIdMap,
            int *const outEntryCount);

    bool mHasHistoricalInfo;
};
} // namespace v402
} // namespace backward
} // namespace latinime
#endif /* LATINIME_BACKWARD_V402_BIGRAM_DICT_CONTENT_H */
