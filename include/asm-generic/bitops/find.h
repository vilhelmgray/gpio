/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_GENERIC_BITOPS_FIND_H_
#define _ASM_GENERIC_BITOPS_FIND_H_

#ifndef find_next_bit
/**
 * find_next_bit - find the next set bit in a memory region
 * @addr: The address to base the search on
 * @offset: The bitnumber to start searching at
 * @size: The bitmap size in bits
 *
 * Returns the bit number for the next set bit
 * If no bits are set, returns @size.
 */
extern unsigned long find_next_bit(const unsigned long *addr, unsigned long
		size, unsigned long offset);
#endif

#ifndef find_next_and_bit
/**
 * find_next_and_bit - find the next set bit in both memory regions
 * @addr1: The first address to base the search on
 * @addr2: The second address to base the search on
 * @offset: The bitnumber to start searching at
 * @size: The bitmap size in bits
 *
 * Returns the bit number for the next set bit
 * If no bits are set, returns @size.
 */
extern unsigned long find_next_and_bit(const unsigned long *addr1,
		const unsigned long *addr2, unsigned long size,
		unsigned long offset);
#endif

#ifndef find_next_zero_bit
/**
 * find_next_zero_bit - find the next cleared bit in a memory region
 * @addr: The address to base the search on
 * @offset: The bitnumber to start searching at
 * @size: The bitmap size in bits
 *
 * Returns the bit number of the next zero bit
 * If no bits are zero, returns @size.
 */
extern unsigned long find_next_zero_bit(const unsigned long *addr, unsigned
		long size, unsigned long offset);
#endif

#ifdef CONFIG_GENERIC_FIND_FIRST_BIT

/**
 * find_first_bit - find the first set bit in a memory region
 * @addr: The address to start the search at
 * @size: The maximum number of bits to search
 *
 * Returns the bit number of the first set bit.
 * If no bits are set, returns @size.
 */
extern unsigned long find_first_bit(const unsigned long *addr,
				    unsigned long size);

/**
 * find_first_zero_bit - find the first cleared bit in a memory region
 * @addr: The address to start the search at
 * @size: The maximum number of bits to search
 *
 * Returns the bit number of the first cleared bit.
 * If no bits are zero, returns @size.
 */
extern unsigned long find_first_zero_bit(const unsigned long *addr,
					 unsigned long size);
#else /* CONFIG_GENERIC_FIND_FIRST_BIT */

#ifndef find_first_bit
#define find_first_bit(addr, size) find_next_bit((addr), (size), 0)
#endif
#ifndef find_first_zero_bit
#define find_first_zero_bit(addr, size) find_next_zero_bit((addr), (size), 0)
#endif

#endif /* CONFIG_GENERIC_FIND_FIRST_BIT */

/**
 * find_next_port_word - find next port word with set bits in a memory region
 * @word_index: location to store bitmap word index of found port word
 * @word_offset: bits offset of the found port word in respective bitmap word
 * @bits: address to base the search on
 * @size: bitmap size in number of ports
 * @offset: port word index to start searching at
 * @port_size: port word size in bits
 *
 * Returns the port index for the next port word with set bits; the respective
 * bitmap word index is stored at the location pointed by @word_index, and the
 * bits offset of the found port word within the respective bitmap word is
 * stored at the location pointed by @word_offset. If no bits are set, returns
 * @size.
 */
size_t find_next_port_word(size_t *const word_index,
			   unsigned int *const word_offset,
			   const unsigned long *const bits, const size_t size,
			   const size_t offset, const unsigned int port_size);

#define find_first_port_word(word_index, word_offset, bits, size, port_size) \
	find_next_port_word((word_index), (word_offset), (bits), (size), 0, \
			    (port_size))

#endif /*_ASM_GENERIC_BITOPS_FIND_H_ */
