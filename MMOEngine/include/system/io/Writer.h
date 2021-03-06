#ifndef WRITER_H_
#define WRITER_H_

#include "system/lang/Object.h"

namespace sys {
  namespace io {

  	class Writer : public Object {
  	public:
  		virtual ~Writer() {
  		}

  		// Closes the stream, flushing it first.
  		virtual void close() = 0;

  		// Flushes the stream.
  		virtual void flush() = 0;

  		// Writes a string.
  		virtual int write(const char* str, int len) = 0;

  		// Writes a portion of a string.
  		virtual int write(const char* str, uint32 off, int len) = 0;
  	};

  } // namespace io
} // namespace sys

using namespace sys::io;

#endif /*WRITER_H_*/
