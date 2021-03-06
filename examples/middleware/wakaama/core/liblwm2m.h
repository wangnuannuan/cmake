/*******************************************************************************
 *
 * Copyright (c) 2013, 2014 Intel Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * The Eclipse Distribution License is available at
 *    http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    David Navarro, Intel Corporation - initial API and implementation
 *    Fabien Fleutot - Please refer to git log
 *    Simon Bernard - Please refer to git log
 *    Toby Jaffey - Please refer to git log
 *    Julien Vermillard - Please refer to git log
 *    Bosch Software Innovations GmbH - Please refer to git log
 *    Pascal Rieux - Please refer to git log
 *******************************************************************************/

/*
 Copyright (c) 2013, 2014 Intel Corporation

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

     * Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
     * Neither the name of Intel Corporation nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 THE POSSIBILITY OF SUCH DAMAGE.

 David Navarro <david.navarro@intel.com>

*/

#ifndef _LWM2M_CLIENT_H_
#define _LWM2M_CLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <time.h>
//#include <sys/time.h>

#ifndef LWM2M_EMBEDDED_MODE
#ifdef MEMORY_TRACE
#include "memtrace.h"
#else
#define lwm2m_malloc malloc
#define lwm2m_free free
#define lwm2m_strdup strdup
#endif
#define lwm2m_strncmp strncmp
#else
void * lwm2m_malloc(size_t s);
void   lwm2m_free(void * p);
char * lwm2m_strdup(const char * str);
int    lwm2m_strncmp(const char * s1, const char * s2, size_t n);
#endif
// This function must return the number of seconds elapsed since origin.
// The origin (Epoch, system boot, etc...) does not matter as this
// function is used only to determine the elapsed time since the last
// call to it.
// In case of error, this must return a negative value.
// Per POSIX specifications, time_t is a signed integer.
// An implementation for POSIX systems is provided in utils.c
time_t lwm2m_gettime(void);
time_t lwm2m_getus();

/*
 * Error code
 */

#define COAP_NO_ERROR                   (uint8_t)0x00
#define COAP_IGNORE                     (uint8_t)0x01

#define COAP_201_CREATED                (uint8_t)0x41
#define COAP_202_DELETED                (uint8_t)0x42
#define COAP_204_CHANGED                (uint8_t)0x44
#define COAP_205_CONTENT                (uint8_t)0x45
#define COAP_400_BAD_REQUEST            (uint8_t)0x80
#define COAP_401_UNAUTHORIZED           (uint8_t)0x81
#define COAP_404_NOT_FOUND              (uint8_t)0x84
#define COAP_405_METHOD_NOT_ALLOWED     (uint8_t)0x85
#define COAP_406_NOT_ACCEPTABLE         (uint8_t)0x86
#define COAP_500_INTERNAL_SERVER_ERROR  (uint8_t)0xA0
#define COAP_501_NOT_IMPLEMENTED        (uint8_t)0xA1
#define COAP_503_SERVICE_UNAVAILABLE    (uint8_t)0xA3

/*
 * Standard Object IDs
 */
#define LWM2M_SECURITY_OBJECT_ID            0
#define LWM2M_SERVER_OBJECT_ID              1
#define LWM2M_ACL_OBJECT_ID                 2
#define LWM2M_DEVICE_OBJECT_ID              3
#define LWM2M_CONN_MONITOR_OBJECT_ID        4
#define LWM2M_FIRMWARE_UPDATE_OBJECT_ID     5
#define LWM2M_LOCATION_OBJECT_ID            6
#define LWM2M_CONN_STATS_OBJECT_ID          7

/*
 * Ressource IDs for the LWM2M Security Object
 */
#define LWM2M_SECURITY_URI_ID                 0
#define LWM2M_SECURITY_BOOTSTRAP_ID           1
#define LWM2M_SECURITY_SECURITY_ID            2
#define LWM2M_SECURITY_PUBLIC_KEY_ID          3
#define LWM2M_SECURITY_SERVER_PUBLIC_KEY_ID   4
#define LWM2M_SECURITY_SECRET_KEY_ID          5
#define LWM2M_SECURITY_SMS_SECURITY_ID        6
#define LWM2M_SECURITY_SMS_KEY_PARAM_ID       7
#define LWM2M_SECURITY_SMS_SECRET_KEY_ID      8
#define LWM2M_SECURITY_SMS_SERVER_NUMBER_ID   9
#define LWM2M_SECURITY_SHORT_SERVER_ID        10
#define LWM2M_SECURITY_HOLD_OFF_ID            11

/*
 * Ressource IDs for the LWM2M Server Object
 */
#define LWM2M_SERVER_SHORT_ID_ID    0
#define LWM2M_SERVER_LIFETIME_ID    1
#define LWM2M_SERVER_MIN_PERIOD_ID  2
#define LWM2M_SERVER_MAX_PERIOD_ID  3
#define LWM2M_SERVER_DISABLE_ID     4
#define LWM2M_SERVER_TIMEOUT_ID     5
#define LWM2M_SERVER_STORING_ID     6
#define LWM2M_SERVER_BINDING_ID     7
#define LWM2M_SERVER_UPDATE_ID      8

#define LWM2M_SECURITY_MODE_PRE_SHARED_KEY  0
#define LWM2M_SECURITY_MODE_RAW_PUBLIC_KEY  1
#define LWM2M_SECURITY_MODE_CERTIFICATE     2
#define LWM2M_SECURITY_MODE_NONE            3


/*
 * Utility functions for sorted linked list
 */

typedef struct _lwm2m_list_t
{
    struct _lwm2m_list_t * next;
    uint16_t    id;
} lwm2m_list_t;

// defined in list.c
// Add 'node' to the list 'head' and return the new list
lwm2m_list_t * lwm2m_list_add(lwm2m_list_t * head, lwm2m_list_t * node);
// Return the node with ID 'id' from the list 'head' or NULL if not found
lwm2m_list_t * lwm2m_list_find(lwm2m_list_t * head, uint16_t id);
// Remove the node with ID 'id' from the list 'head' and return the new list
lwm2m_list_t * lwm2m_list_remove(lwm2m_list_t * head, uint16_t id, lwm2m_list_t ** nodeP);
// Return the lowest unused ID in the list 'head'
uint16_t lwm2m_list_newId(lwm2m_list_t * head);
// Free a list. Do not use if nodes contain allocated pointers as it calls lwm2m_free on nodes only.
// If the nodes of the list need to do more than just "free()" their instances, don't use lwm2m_list_free().
void lwm2m_list_free(lwm2m_list_t * head);

#define LWM2M_LIST_ADD(H,N) lwm2m_list_add((lwm2m_list_t *)H, (lwm2m_list_t *)N);
#define LWM2M_LIST_RM(H,I,N) lwm2m_list_remove((lwm2m_list_t *)H, I, (lwm2m_list_t **)N);
#define LWM2M_LIST_FIND(H,I) lwm2m_list_find((lwm2m_list_t *)H, I)
#define LWM2M_LIST_FREE(H) lwm2m_list_free((lwm2m_list_t *)H)


/*
 *  Resource values
 */

// defined in utils.c
int lwm2m_PlainTextToInt64(uint8_t * buffer, int length, int64_t * dataP);
int lwm2m_PlainTextToFloat64(uint8_t * buffer, int length, double * dataP);

/*
 * These utility functions allocate a new buffer storing the plain text
 * representation of data. They return the size in bytes of the buffer
 * or 0 in case of error.
 * There is no trailing '\0' character in the buffer.
 */
size_t lwm2m_int64ToPlainText(int64_t data, uint8_t ** bufferP);
size_t lwm2m_float64ToPlainText(double data, uint8_t ** bufferP);
size_t lwm2m_boolToPlainText(bool data, uint8_t ** bufferP);


/*
 * TLV
 */

#define LWM2M_TLV_HEADER_MAX_LENGTH 6

/*
 * Bitmask for the lwm2m_tlv_t::flag
 * LWM2M_TLV_FLAG_STATIC_DATA specifies that lwm2m_tlv_t::value
 * points to static memory and must no be freeed by the caller.
 * LWM2M_TLV_FLAG_TEXT_FORMAT specifies that lwm2m_tlv_t::value
 * is expressed or requested in plain text format.
 */
#define LWM2M_TLV_FLAG_STATIC_DATA   0x01
#define LWM2M_TLV_FLAG_TEXT_FORMAT   0x02

#ifdef LWM2M_BOOTSTRAP
#define LWM2M_TLV_FLAG_BOOTSTRAPPING 0x04
#endif

/*
 * Bits 7 and 6 of assigned values for LWM2M_TYPE_RESOURCE,
 * LWM2M_TYPE_MULTIPLE_RESOURCE, LWM2M_TYPE_RESOURCE_INSTANCE
 * and LWM2M_TYPE_OBJECT_INSTANCE must match the ones defined
 * in the TLV format from LWM2M TS ??6.3.3
 *
 */
typedef enum
{
    LWM2M_TYPE_RESOURCE = 0xC0,
    LWM2M_TYPE_MULTIPLE_RESOURCE = 0x80,
    LWM2M_TYPE_RESOURCE_INSTANCE = 0x40,
    LWM2M_TYPE_OBJECT_INSTANCE = 0x00
} lwm2m_tlv_type_t;

typedef enum
{
    LWM2M_TYPE_UNDEFINED = 0,
    LWM2M_TYPE_STRING,
    LWM2M_TYPE_INTEGER,
    LWM2M_TYPE_FLOAT,
    LWM2M_TYPE_BOOLEAN,
    LWM2M_TYPE_OPAQUE,
    LWM2M_TYPE_TIME,
    LWM2M_TYPE_OBJECT_LINK
} lwm2m_data_type_t;

typedef struct
{
    uint8_t     flags;
    lwm2m_tlv_type_t  type;
    lwm2m_data_type_t dataType;
    uint16_t    id;
    size_t      length;
    uint8_t *   value;
} lwm2m_tlv_t;

lwm2m_tlv_t * lwm2m_tlv_new(int size);
int lwm2m_tlv_parse(uint8_t * buffer, size_t bufferLen, lwm2m_tlv_t ** dataP);
int lwm2m_tlv_serialize(int size, lwm2m_tlv_t * tlvP, uint8_t ** bufferP);
void lwm2m_tlv_free(int size, lwm2m_tlv_t * tlvP);

void lwm2m_tlv_encode_int(int64_t data, lwm2m_tlv_t * tlvP);
int lwm2m_tlv_decode_int(lwm2m_tlv_t * tlvP, int64_t * dataP);
void lwm2m_tlv_encode_float(double data, lwm2m_tlv_t * tlvP);
int lwm2m_tlv_decode_float(lwm2m_tlv_t * tlvP, double * dataP);
void lwm2m_tlv_encode_bool(bool data, lwm2m_tlv_t * tlvP);
int lwm2m_tlv_decode_bool(lwm2m_tlv_t * tlvP, bool * dataP);
void lwm2m_tlv_include(lwm2m_tlv_t * subTlvP, size_t count, lwm2m_tlv_t * tlvP);


/*
 * These utility functions fill the buffer with a TLV record containing
 * the data. They return the size in bytes of the TLV record, 0 in case
 * of error.
 */
int lwm2m_intToTLV(lwm2m_tlv_type_t type, int64_t data, uint16_t id, uint8_t * buffer, size_t buffer_len);
int lwm2m_boolToTLV(lwm2m_tlv_type_t type, bool value, uint16_t id, uint8_t * buffer, size_t buffer_len);
int lwm2m_opaqueToTLV(lwm2m_tlv_type_t type, uint8_t * dataP, size_t data_len, uint16_t id, uint8_t * buffer, size_t buffer_len);
int lwm2m_decodeTLV(uint8_t * buffer, size_t buffer_len, lwm2m_tlv_type_t * oType, uint16_t * oID, size_t * oDataIndex, size_t * oDataLen);
int lwm2m_opaqueToInt(uint8_t * buffer, size_t buffer_len, int64_t * dataP);
int lwm2m_opaqueToFloat(uint8_t * buffer, size_t buffer_len, double * dataP);

/*
 * URI
 *
 * objectId is always set
 * if instanceId or resourceId is greater than LWM2M_URI_MAX_ID, it means it is not specified
 *
 */

#define LWM2M_MAX_ID   ((uint16_t)0xFFFF)

#define LWM2M_URI_FLAG_OBJECT_ID    (uint8_t)0x04
#define LWM2M_URI_FLAG_INSTANCE_ID  (uint8_t)0x02
#define LWM2M_URI_FLAG_RESOURCE_ID  (uint8_t)0x01

#define LWM2M_URI_IS_SET_INSTANCE(uri) ((uri->flag & LWM2M_URI_FLAG_INSTANCE_ID) != 0)
#define LWM2M_URI_IS_SET_RESOURCE(uri) ((uri->flag & LWM2M_URI_FLAG_RESOURCE_ID) != 0)

typedef struct
{
    uint8_t     flag;           // indicates which segments are set
    uint16_t    objectId;
    uint16_t    instanceId;
    uint16_t    resourceId;
} lwm2m_uri_t;


#define LWM2M_STRING_ID_MAX_LEN 6

// Parse an URI in LWM2M format and fill the lwm2m_uri_t.
// Return the number of characters read from buffer or 0 in case of error.
// Valid URIs: /1, /1/, /1/2, /1/2/, /1/2/3
// Invalid URIs: /, //, //2, /1//, /1//3, /1/2/3/, /1/2/3/4
int lwm2m_stringToUri(const char * buffer, size_t buffer_len, lwm2m_uri_t * uriP);


/*
 * LWM2M Objects
 *
 * For the read callback, if *numDataP is not zero, *dataArrayP is pre-allocated
 * and contains the list of resources to read.
 *
 */

typedef struct _lwm2m_object_t lwm2m_object_t;

typedef uint8_t (*lwm2m_read_callback_t) (uint16_t instanceId, int * numDataP, lwm2m_tlv_t ** dataArrayP, lwm2m_object_t * objectP);
typedef uint8_t (*lwm2m_write_callback_t) (uint16_t instanceId, int numData, lwm2m_tlv_t * dataArray, lwm2m_object_t * objectP);
typedef uint8_t (*lwm2m_execute_callback_t) (uint16_t instanceId, uint16_t resourceId, uint8_t * buffer, int length, lwm2m_object_t * objectP);
typedef uint8_t (*lwm2m_create_callback_t) (uint16_t instanceId, int numData, lwm2m_tlv_t * dataArray, lwm2m_object_t * objectP);
typedef uint8_t (*lwm2m_delete_callback_t) (uint16_t instanceId, lwm2m_object_t * objectP);
typedef void (*lwm2m_close_callback_t) (lwm2m_object_t * objectP);

struct _lwm2m_object_t
{
    uint16_t                 objID;
    lwm2m_list_t *           instanceList;
    lwm2m_read_callback_t    readFunc;
    lwm2m_write_callback_t   writeFunc;
    lwm2m_execute_callback_t executeFunc;
    lwm2m_create_callback_t  createFunc;
    lwm2m_delete_callback_t  deleteFunc;
    lwm2m_close_callback_t   closeFunc;
    void *                   userData;
};

/*
 * LWM2M Servers
 *
 * Since LWM2M Server Object instances are not accessible to LWM2M servers,
 * there is no need to store them as lwm2m_objects_t
 */

typedef enum
{
    STATE_DEREGISTERED = 0,   // not registered
    STATE_REG_PENDING,        // registration pending
    STATE_REGISTERED,         // successfully registered
    STATE_REG_FAILED,         // last registration failed
    STATE_REG_UPDATE_PENDING, // registration update pending
    STATE_DEREG_PENDING       // deregistration pending
} lwm2m_status_t;

typedef enum
{
    BINDING_UNKNOWN = 0,
    BINDING_U,   // UDP
    BINDING_UQ,  // UDP queue mode
    BINDING_S,   // SMS
    BINDING_SQ,  // SMS queue mode
    BINDING_US,  // UDP plus SMS
    BINDING_UQS  // UDP queue mode plus SMS
} lwm2m_binding_t;

typedef struct _lwm2m_server_
{
    struct _lwm2m_server_ * next;   // matches lwm2m_list_t::next
    uint16_t          secObjInstID; // matches lwm2m_list_t::id
    uint16_t          shortID;      // servers short ID, may be 0 for bootstrap server
    time_t            lifetime;     // lifetime of the registration in sec or 0 if default value (86400 sec), also used as hold off time for the bootstrap server
    time_t            registration; // date of the last registration in sec
    lwm2m_binding_t   binding;      // client connection mode with this server
    void *            sessionH;
    lwm2m_status_t    status;
    char *            location;
} lwm2m_server_t;


/*
 * LWM2M result callback
 *
 * When used with an observe, if 'data' is not nil, 'status' holds the observe counter.
 */
typedef void (*lwm2m_result_callback_t) (uint16_t clientID, lwm2m_uri_t * uriP, int status, uint8_t * data, int dataLength, void * userData);

/*
 * LWM2M Observations
 *
 * Used to store observation of remote clients resources.
 * status STATE_REG_PENDING means the observe request was sent to the client but not yet answered.
 * status STATE_REGISTERED means the client acknowledged the observe request.
 * status STATE_DEREG_PENDING means the user canceled the request before the client answered it.
 */

typedef struct _lwm2m_observation_
{
    struct _lwm2m_observation_ * next;  // matches lwm2m_list_t::next
    uint16_t                     id;    // matches lwm2m_list_t::id
    struct _lwm2m_client_ * clientP;
    lwm2m_uri_t             uri;
    lwm2m_status_t          status;
    lwm2m_result_callback_t callback;
    void *                  userData;
} lwm2m_observation_t;

/*
 * LWM2M Clients
 *
 * Be careful not to mix lwm2m_client_object_t used to store list of objects of remote clients
 * and lwm2m_object_t describing objects exposed to remote servers.
 *
 */

typedef struct _lwm2m_client_object_
{
    struct _lwm2m_client_object_ * next; // matches lwm2m_list_t::next
    uint16_t                 id;         // matches lwm2m_list_t::id
    lwm2m_list_t *           instanceList;
} lwm2m_client_object_t;

typedef struct _lwm2m_client_
{
    struct _lwm2m_client_ * next;       // matches lwm2m_list_t::next
    uint16_t                internalID; // matches lwm2m_list_t::id
    char *                  name;
    lwm2m_binding_t         binding;
    char *                  msisdn;
    char *                  altPath;
    uint32_t                lifetime;
    time_t                  endOfLife;
    void *                  sessionH;
    lwm2m_client_object_t * objectList;
    lwm2m_observation_t *   observationList;
} lwm2m_client_t;


/*
 * LWM2M transaction
 *
 * Adaptation of Erbium's coap_transaction_t
 */

typedef enum
{
    ENDPOINT_UNKNOWN = 0,
    ENDPOINT_CLIENT,
    ENDPOINT_SERVER
} lwm2m_endpoint_type_t;

typedef struct _lwm2m_transaction_ lwm2m_transaction_t;

typedef void (*lwm2m_transaction_callback_t) (lwm2m_transaction_t * transacP, void * message);

struct _lwm2m_transaction_
{
    lwm2m_transaction_t * next;  // matches lwm2m_list_t::next
    uint16_t              mID;   // matches lwm2m_list_t::id
    lwm2m_endpoint_type_t peerType;
    void *                peerP;
    uint8_t               ack_received; // indicates, that the ACK was received
    time_t                response_timeout; // timeout to wait for response, if token is used. When 0, use calculated acknowledge timeout.
    uint8_t  retrans_counter;
    time_t   retrans_time;
    char objStringID[LWM2M_STRING_ID_MAX_LEN];
    char instanceStringID[LWM2M_STRING_ID_MAX_LEN];
    char resourceStringID[LWM2M_STRING_ID_MAX_LEN];
    void * message;
    uint16_t buffer_len;
    uint8_t * buffer;
    lwm2m_transaction_callback_t callback;
    void * userData;
};

/*
 * LWM2M observed resources
 */
typedef struct _lwm2m_watcher_
{
    struct _lwm2m_watcher_ * next;

    lwm2m_server_t * server;
    uint8_t token[8];
    size_t tokenLen;
    uint32_t counter;
    uint16_t lastMid;
} lwm2m_watcher_t;

typedef struct _lwm2m_observed_
{
    struct _lwm2m_observed_ * next;

    lwm2m_uri_t uri;
    lwm2m_watcher_t * watcherList;
} lwm2m_observed_t;

#ifdef LWM2M_BOOTSTRAP

typedef enum {
    NOT_BOOTSTRAPPED = 0,
    BOOTSTRAP_REQUESTED,
    BOOTSTRAP_CLIENT_HOLD_OFF,
    BOOTSTRAP_INITIATED,
    BOOTSTRAP_PENDING,
    BOOTSTRAP_FINISHED,
    BOOTSTRAP_FAILED,
    BOOTSTRAPPED
} lwm2m_bootstrap_state_t;

#endif
/*
 * LWM2M Context
 */

// The session handle MUST uniquely identify a peer.
typedef void * (*lwm2m_connect_server_callback_t)(uint16_t secObjInstID, void * userData);
// The session handle MUST uniquely identify a peer.
typedef uint8_t (*lwm2m_buffer_send_callback_t)(void * sessionH, uint8_t * buffer, size_t length, void * userData);

#ifdef LWM2M_BOOTSTRAP_SERVER_MODE
// In all the following APIs, the session handle MUST uniquely identify a peer.

// LWM2M bootstrap callback
// When a LWM2M client requests bootstrap information, the callback is called with status COAP_NO_ERROR, uriP is nil and
// name is set. The callback must return a COAP_* error code. COAP_204_CHANGED for success.
// After a lwm2m_bootstrap_delete() or a lwm2m_bootstrap_write(), the callback is called with the status returned by the
// client, the URI of the operation (may be nil) and name is nil. The callback return value is ignored.
typedef int (*lwm2m_bootstrap_callback_t) (void * sessionH, uint8_t status, lwm2m_uri_t * uriP, char * name, void * userData);
#endif

typedef struct
{
#ifdef LWM2M_CLIENT_MODE
#ifdef LWM2M_BOOTSTRAP
    lwm2m_bootstrap_state_t bsState;
    time_t              bsStart;
#endif
    char *              endpointName;
    char *              msisdn;
    char *              altPath;
    lwm2m_server_t *    bootstrapServerList;
    lwm2m_server_t *    serverList;
    lwm2m_object_t **   objectList;
    uint16_t            numObject;
    lwm2m_observed_t *  observedList;
#endif
#ifdef LWM2M_SERVER_MODE
    lwm2m_client_t *        clientList;
    lwm2m_result_callback_t monitorCallback;
    void *                  monitorUserData;
#endif
#ifdef LWM2M_BOOTSTRAP_SERVER_MODE
    lwm2m_bootstrap_callback_t bootstrapCallback;
    void *                     bootstrapUserData;
#endif
    uint16_t                nextMID;
    lwm2m_transaction_t *   transactionList;
    // communication layer callbacks
    lwm2m_connect_server_callback_t connectCallback;
    lwm2m_buffer_send_callback_t    bufferSendCallback;
    void *                          userData;
} lwm2m_context_t;


// initialize a liblwm2m context.
lwm2m_context_t * lwm2m_init(lwm2m_connect_server_callback_t connectCallback, lwm2m_buffer_send_callback_t bufferSendCallback, void * userData);
// close a liblwm2m context.
void lwm2m_close(lwm2m_context_t * contextP);

// perform any required pending operation and adjust timeoutP to the maximal time interval to wait in seconds.
int lwm2m_step(lwm2m_context_t * contextP, time_t * timeoutP);
// dispatch received data to liblwm2m
void lwm2m_handle_packet(lwm2m_context_t * contextP, uint8_t * buffer, int length, void * fromSessionH);

#ifdef LWM2M_CLIENT_MODE
// configure the client side with the Endpoint Name, binding, MSISDN (can be nil), alternative path
// for objects (can be nil) and a list of objects.
// LWM2M Security Object (ID 0) must be present with either a bootstrap server or a LWM2M server and
// its matching LWM2M Server Object (ID 1) instance
int lwm2m_configure(lwm2m_context_t * contextP, const char * endpointName, const char * msisdn, const char * altPath, uint16_t numObject, lwm2m_object_t * objectList[]);

// create objects for known LWM2M Servers.
int lwm2m_start(lwm2m_context_t * contextP);

// send a registration update to the server specified by the server short identifier
int lwm2m_update_registration(lwm2m_context_t * contextP, uint16_t shortServerID);

void lwm2m_resource_value_changed(lwm2m_context_t * contextP, lwm2m_uri_t * uriP);
#endif

#ifdef LWM2M_SERVER_MODE
// Clients registration/deregistration monitoring API.
// When a LWM2M client registers, the callback is called with status CREATED_2_01.
// When a LWM2M client deregisters, the callback is called with status DELETED_2_02.
// clientID is the internal ID of the LWM2M Client.
// The callback's parameters uri, data, dataLength are always NULL.
// The lwm2m_client_t is present in the lwm2m_context_t's clientList when the callback is called. On a deregistration, it deleted when the callback returns.
void lwm2m_set_monitoring_callback(lwm2m_context_t * contextP, lwm2m_result_callback_t callback, void * userData);

// Device Management APIs
int lwm2m_dm_read(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, lwm2m_result_callback_t callback, void * userData);
int lwm2m_dm_write(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, uint8_t * buffer, int length, lwm2m_result_callback_t callback, void * userData);
int lwm2m_dm_execute(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, uint8_t * buffer, int length, lwm2m_result_callback_t callback, void * userData);
int lwm2m_dm_create(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, uint8_t * buffer, int length, lwm2m_result_callback_t callback, void * userData);
int lwm2m_dm_delete(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, lwm2m_result_callback_t callback, void * userData);

// Information Reporting APIs
int lwm2m_observe(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, lwm2m_result_callback_t callback, void * userData);
int lwm2m_observe_cancel(lwm2m_context_t * contextP, uint16_t clientID, lwm2m_uri_t * uriP, lwm2m_result_callback_t callback, void * userData);
#endif

#ifdef LWM2M_BOOTSTRAP_SERVER_MODE
// Clients bootstrap request monitoring API.
// When a LWM2M client sends a bootstrap request, the callback is called with the client's endpoint name.
void lwm2m_set_bootstrap_callback(lwm2m_context_t * contextP, lwm2m_bootstrap_callback_t callback, void * userData);

// Boostrap Interface APIs
// if uriP is nil, a "Delete /" is sent to the client
int lwm2m_bootstrap_delete(lwm2m_context_t * contextP, void * sessionH, lwm2m_uri_t * uriP);
int lwm2m_bootstrap_write(lwm2m_context_t * contextP, void * sessionH, lwm2m_uri_t * uriP, uint8_t * buffer, size_t length);
int lwm2m_bootstrap_finish(lwm2m_context_t * contextP, void * sessionH);

#endif

#ifdef __cplusplus
}
#endif

#endif
