/**
 * CPPShift Memory Pool v2.0.0
 *
 * Copyright 2020-present Sapir Shemer, DevShift (devshift.biz)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Sapir Shemer
 */
#pragma once

#include "MemoryPoolData.h"
#include <cstddef>
#include <memory>

namespace CPPShift::Memory {
	class MemoryPoolManager {
	public:
		/**
		 * Creates a memory pool structure and initializes it
		 * 
		 * @param size_t block_size Defines the default size of a block in the pool, by default uses MEMORYPOOL_DEFAULT_BLOCK_SIZE
		 * 
		 * @returns MemoryPool* Pointer to a new memory pool structure
		 */
		static MemoryPool* create(size_t block_size = MEMORYPOOL_DEFAULT_BLOCK_SIZE);

		/**
		 * Create a new standalone memory block unattached to any memory pool
		 * 
		 * @param size_t block_size Defines the default size of a block in the pool, by default uses MEMORYPOOL_DEFAULT_BLOCK_SIZE
		 * 
		 * @returns SMemoryBlockHeader* Pointer to the header of the memory block
		 */
		static SMemoryBlockHeader* createMemoryBlock(size_t block_size = MEMORYPOOL_DEFAULT_BLOCK_SIZE);

		/**
		 * Allocates memory in a pool
		 * 
		 * @param MemoryPool* mp Memory pool to allocate memory in
		 * @param size_t size Size to allocate in memory pool
		 * 
		 * @returns void* Pointer to the newly allocate space
		 */
		static void* allocate(MemoryPool* mp, size_t size);

		/**
		 * Re-allocates memory in a pool
		 *
		 * @param void* unit_pointer_start Pointer to the object to re-allocate
		 * @param size_t new_size New size to allocate in memory pool
		 *
		 * @returns void* Pointer to the newly allocate space
		 */
		static void* reallocate(void* unit_pointer_start, size_t new_size);

		/**
		 * Frees memory in a pool
		 *
		 * @param void* unit_pointer_start Pointer to the object to free
		 */
		static void free(void* unit_pointer_start);
	};
}

// Override new operators to create with memory pool
extern void* operator new(size_t size, CPPShift::Memory::MemoryPool* mp);
extern void* operator new[](size_t size, CPPShift::Memory::MemoryPool* mp);