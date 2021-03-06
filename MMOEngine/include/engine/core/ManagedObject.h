/*
 *	engine/core/ManagedObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef MANAGEDOBJECT_H_
#define MANAGEDOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#ifndef likely
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif
#endif
#include "engine/util/json_utils.h"

namespace engine {
namespace core {

class ObjectUpdateToDatabaseTask;

} // namespace core
} // namespace engine

using namespace engine::core;

#include "system/lang/Object.h"

#include "system/thread/ReadWriteLock.h"

#include "system/thread/Lockable.h"

#include "system/io/Serializable.h"

#include "system/io/ObjectInputStream.h"

#include "system/io/ObjectOutputStream.h"

#include "engine/orb/object/DistributedObjectServant.h"

#include "engine/util/JSONSerializationType.h"

namespace engine {
namespace core {

class ManagedObject : public DistributedObjectStub {
public:
	ManagedObject();

	void updateForWrite();

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void lock(Lockable* obj);

	void rlock(bool doLock = true);

	void rlock(ManagedObject* obj);

	void rlock(Lockable* obj);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void setLockName(const String& name);

	bool notifyDestroy();

	void writeObject(ObjectOutputStream* stream);

	void writeJSON(JSONSerializationType& j);

	void readObject(ObjectInputStream* stream);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	/**
	 * Gets called when this objects is loaded from database
	 * @pre { this locked }
	 * @post { this locked }
	 */
	void notifyLoadFromDatabase();

	DistributedObjectServant* getServant();

	void initializeTransientMembers();

	void updateToDatabase();

	void queueUpdateToDatabaseTask();

	void clearUpdateToDatabaseTask();

	unsigned int getLastCRCSave() const;

	void setLastCRCSave(unsigned int crc);

	bool isPersistent();

	int getPersistenceLevel() const;

	/**
	 * Sets the persistence level of the object
	 * level 0 makes the object transient
	 * level 1 makes the object persistent but its not auto updated
	 * level 2 makes the object auto update every 5 minutes
	 * level 3 makes the object update to database after each change (write unlock)
	 */
	void setPersistent(int level);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead() const;

	void _setImplementation(DistributedObjectServant* servant);

protected:
	ManagedObject(DummyConstructorParameter* param);

	virtual ~ManagedObject();

	void __updateForWrite();

	void __lock(bool doLock = true);

	void __lock(ManagedObject* obj);

	void __lock(Lockable* obj);

	void __rlock(bool doLock = true);

	void __rlock(ManagedObject* obj);

	void __rlock(Lockable* obj);

	void __wlock(bool doLock = true);

	void __wlock(ManagedObject* obj);

	void __unlock(bool doLock = true);

	void __runlock(bool doLock = true);

	void __setLockName(const String& name);

	bool __notifyDestroy();

	void __writeObject(ObjectOutputStream* stream);

	void __writeJSON(JSONSerializationType& j);

	DistributedObjectServant* __getServant();

	friend class ManagedObjectHelper;
};

class ManagedObjectImplementation : public DistributedObjectServant {
protected:
	int persistenceLevel;

private:
	unsigned int lastCRCSave;

protected:
	ObjectUpdateToDatabaseTask* updateToDatabaseTask;

	String _className;

public:
	ManagedObjectImplementation();
	ManagedObjectImplementation(DummyConstructorParameter* param);

	void updateForWrite();

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void lock(Lockable* obj);

	void rlock(bool doLock = true);

	void rlock(ManagedObject* obj);

	void rlock(Lockable* obj);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void setLockName(const String& name);

	bool notifyDestroy();

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	/**
	 * Gets called when this objects is loaded from database
	 * @pre { this locked }
	 * @post { this locked }
	 */
	virtual void notifyLoadFromDatabase();

	DistributedObjectServant* getServant();

	virtual void initializeTransientMembers();

	void updateToDatabase();

	virtual void queueUpdateToDatabaseTask();

	void clearUpdateToDatabaseTask();

	unsigned int getLastCRCSave() const;

	void setLastCRCSave(unsigned int crc);

	bool isPersistent();

	int getPersistenceLevel() const;

protected:
	void _setClassName(const String& name);

public:
	/**
	 * Sets the persistence level of the object
	 * level 0 makes the object transient
	 * level 1 makes the object persistent but its not auto updated
	 * level 2 makes the object auto update every 5 minutes
	 * level 3 makes the object update to database after each change (write unlock)
	 */
	void setPersistent(int level);

	WeakReference<ManagedObject*> _this;

	operator const ManagedObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
	virtual void writeJSON(nlohmann::json& j);
protected:
	virtual ~ManagedObjectImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class ManagedObject;
};

class ManagedObjectAdapter : public DistributedObjectAdapter {
public:
	ManagedObjectAdapter(ManagedObject* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void updateForWrite();

	void lock(bool doLock);

	void lock(ManagedObject* obj);

	void rlock(bool doLock);

	void rlock(ManagedObject* obj);

	void wlock(bool doLock);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock);

	void runlock(bool doLock);

	void setLockName(const String& name);

	bool notifyDestroy();

	void notifyLoadFromDatabase();

	void initializeTransientMembers();

	void updateToDatabase();

	void queueUpdateToDatabaseTask();

	void clearUpdateToDatabaseTask();

	unsigned int getLastCRCSave() const;

	void setLastCRCSave(unsigned int crc);

	bool isPersistent();

	int getPersistenceLevel() const;

};

class ManagedObjectHelper : public DistributedObjectClassHelper, public Singleton<ManagedObjectHelper> {
	static ManagedObjectHelper* staticInitializer;

public:
	ManagedObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ManagedObjectHelper>;
};

} // namespace core
} // namespace engine

using namespace engine::core;

#endif /*MANAGEDOBJECT_H_*/
