/*!
 * \file 	astTrunk.h
 * \brief 	SCCP PBX Asterisk Header
 * \author 	Marcello Ceshia
 * \author 	Diederik de Groot <ddegroot [at] users.sourceforge.net>
 * \note        This program is free software and may be modified and distributed under the terms of the GNU Public License.
 *		See the LICENSE file at the top of the source tree.
 *
 * $Date: 2010-10-23 20:04:30 +0200 (Sat, 23 Oct 2010) $
 * $Revision: 2044 $  
 */

#ifndef SCCP_AST_MAJOR_H_
#    define SCCP_AST_MAJOR_H_

#    include <config.h>
#    include "../../common.h"

#    define pbx_channel_unref ast_channel_unref
#    define sccp_sched_context_destroy sched_context_destroy

typedef struct ast_format_cap ast_format_t;
int skinny_codecs2pbx_codec_pref(skinny_codec_t * skinny_codecs, struct ast_codec_pref *astCodecPref);
int sccp_wrapper_asterisk_set_rtp_peer(PBX_CHANNEL_TYPE * ast, PBX_RTP_TYPE * rtp, PBX_RTP_TYPE * vrtp, PBX_RTP_TYPE * trtp, int codecs, int nat_active);
void *sccp_do_monitor(void *data);
int sccp_restart_monitor(void);
const char *pbx_getformatname(const struct ast_format *format);
char *pbx_getformatname_multiple(char *buf, size_t size, struct ast_format_cap *format);

/* Redefinitions for asterisk-trunk, need to be sorted  */
#    define pbx_channel_name(x) ast_channel_name(x)

#    undef pbx_channel_uniqueid
#    undef pbx_channel_flags
#    undef pbx_channel_call_forward
#    undef pbx_channel_appl
#    undef pbx_channel_state
#    undef pbx_channel_pbx
#    undef pbx_channel_hangupcause
#    undef pbx_channel_set_hangupcause
#    undef pbx_channel_softhangup
#    undef pbx_channel_context
#    undef pbx_channel_nativeformats
#    undef pbx_channel_exten
#    undef pbx_channel_macroexten
#    undef pbx_channel_macrocontext
#    undef pbx_channel_dialcontext
#    undef pbx_channel_callgroup
#    undef pbx_channel_masq
#    undef pbx_channel_setwhentohangup_tv
#    undef pbx_channel_blocker
#    undef pbx_channel_blockproc
#    undef pbx_channel_tech
#    undef pbx_channel_bridge
#    undef pbx_channel_set_bridge
#    undef pbx_channel_language

#    define pbx_channel_uniqueid(_a) ast_channel_uniqueid(_a)
#    define pbx_channel_flags(_a) ast_channel_flags(_a)
#    define pbx_channel_call_forward(_a) ast_channel_call_forward(_a)
#    define pbx_channel_appl(_a) ast_channel_appl(_a)
#    define pbx_channel_state(_a) ast_channel_state(_a)
#    define pbx_channel_pbx(_a) ast_channel_pbx(_a)
#    define pbx_channel_hangupcause(_a) ast_channel_hangupcause(_a)
#    define pbx_channel_set_hangupcause(_a, _b) ast_channel_hangupcause_set(_a, _b)
#    define pbx_channel_softhangup(_a) ast_channel_softhangup_internal_flag(_a)
#    define pbx_channel_set_hangupcause(_a, _b) ast_channel_hangupcause_set(_a, _b)
#    define pbx_channel_context(_a) ast_channel_context(_a)
#    define pbx_channel_nativeformats(_a) ast_channel_nativeformats(_a)
#    define pbx_channel_exten(_a) ast_channel_exten(_a)
#    define pbx_channel_macroexten(_a) ast_channel_macroexten(_a)
#    define pbx_channel_macrocontext(_a) ast_channel_macrocontext(_a)
#    define pbx_channel_dialcontext(_a) ast_channel_dialcontext(_a)
#    define pbx_channel_callgroup(_a) ast_channel_callgroup(_a)
#    define pbx_channel_masq(_a) ast_channel_masq(_a)
#    define pbx_channel_setwhentohangup_tv(_a, _b) ast_channel_setwhentohangup_tv(_a, _b)
#    define pbx_channel_blocker(_a) ast_channel_blocker(_a)
#    define pbx_channel_blockproc(_a) ast_channel_blockproc(_a)
#    define pbx_channel_tech(_a) ast_channel_tech(_a)
#    define pbx_channel_bridge(_a) ast_channel_bridge(_a)
#    define pbx_channel_set_bridge(_a, _b) ast_channel_internal_bridge_set(_a, _b)
#    define pbx_channel_language(_a) ast_channel_language(_a)

int pbx_manager_register(const char *action, int authority, int (*func)(struct mansession *s, const struct message *m), const char *synopsis, const char *description);

#    undef CS_AST_CHANNEL_PVT
#    undef CS_AST_CHANNEL_PVT_TYPE
#    undef CS_AST_CHANNEL_PVT_CMP_TYPE

#    define CS_AST_CHANNEL_PVT(_a) ((sccp_channel_t*)ast_channel_tech_pvt(_a))
#    define CS_AST_CHANNEL_PVT_TYPE(_a) ast_channel_tech(_a)->type
#    define CS_AST_CHANNEL_PVT_CMP_TYPE(_a,_b) !strncasecmp(CS_AST_CHANNEL_PVT_TYPE(_a), _b, strlen(_b))

#    define NEWCONST const							// old functions used without const
#    define OLDCONST								// new function used with const

#    define CLI_AMI_OUTPUT(fd, s, ...) 										\
	if (NULL != s) {											\
		astman_append(s, __VA_ARGS__);									\
		local_total++;											\
	} else {												\
		ast_cli(fd, __VA_ARGS__);									\
	}

#    define CLI_AMI_OUTPUT_PARAM(param, width, fmt, ...) 							\
	if (NULL != s) {											\
		astman_append(s, "%s: " fmt "\r\n", param, __VA_ARGS__);					\
		local_total++;											\
	} else {												\
		ast_cli(fd, "%-*.*s %s " fmt "\n", width, width, param, ":", __VA_ARGS__);			\
	}

#    define CLI_AMI_OUTPUT_BOOL(param, width, value) 								\
	if (NULL != s) {											\
		astman_append(s, "%s: %s\r\n", param, ((value) ? "on" : "off"));				\
		local_total++;											\
	} else {												\
		ast_cli(fd, "%-*.*s %s %s\n", width, width, param, ":", ((value) ? "on" : "off")); 		\
	}

#    define CLI_AMI_OUTPUT_YES_NO(param, width, value) 								\
	if (NULL != s) {											\
		astman_append(s, "%s: %s\r\n", param, ((value) ? "yes" : "no"));				\
		local_total++;											\
	} else {												\
		ast_cli(fd, "%-*.*s %s %s\n", width, width, param, ":", ((value) ? "yes" : "no")); 		\
	}

#    define CLI_AMI_ERROR(fd, s, m, fmt, ...) 									\
/*	pbx_log(LOG_WARNING, "SCCP CLI ERROR: " fmt, __VA_ARGS__);						*/\
	if (NULL != s) {											\
		astman_send_error(s, m, fmt);									\
		local_total++;											\
	} else {												\
		ast_cli(fd, "SCCP CLI ERROR: " fmt, __VA_ARGS__);						\
	}													\
	return RESULT_FAILURE;

// CLI_ENTRY
//   param1=registration_name
//   param2=function to execute when called
//   param3=cli string to be types as array of strings
//   param4=registration description
//   param5=usage string
#    define CLI_AMI_ENTRY(_FUNCTION_NAME,_CALLED_FUNCTION,_DESCR,_USAGE, _COMPLETER_REPEAT)			\
	static int manager_ ## _FUNCTION_NAME(struct mansession *s, const struct message *m)			\
	{													\
		const char *id = astman_get_header(m, "ActionID");						\
/*		static char *cli_ami_command[] = { CLI_COMMAND, NULL};					*/	\
/*		static char *ami_command = AMI_COMMAND;							*/	\
/*		cli_ami_command[0] = ami_command;							*/	\
		static char *cli_ami_params[] = { CLI_COMMAND, CLI_AMI_PARAMS };				\
		static char *arguments[ARRAY_LEN(cli_ami_params)];						\
		uint8_t x=0; 											\
		uint8_t i=0; 											\
		for (x=0, i=0;x<ARRAY_LEN(cli_ami_params);x++) {						\
			if(NULL != cli_ami_params[x] && strlen(cli_ami_params[x]) > 0){ 			\
				arguments[i++]=sccp_strdupa(astman_get_header(m, cli_ami_params[x])); 		\
			} 											\
		}												\
		char idtext[256] = "";										\
		int total = 0;											\
		if (!pbx_strlen_zero(id))									\
			snprintf(idtext, sizeof(idtext), "ActionID: %s\r\n", id);				\
		astman_send_ack(s, m, AMI_COMMAND);								\
		_CALLED_FUNCTION(-1, &total, s, m, ARRAY_LEN(arguments), arguments);				\
		astman_append(s,										\
		"Event: " _DESCR " Complete\r\n"								\
		"EventList: Complete\r\n"									\
		"ListItems: %d\r\n"										\
		"%s"												\
		"\r\n\r\n", total, idtext);  									\
		return 0;											\
	}													\
														\
	static char * cli_ ## _FUNCTION_NAME(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a) {	\
		const char *cli_command[] = { CLI_COMMAND, NULL };						\
		static sccp_cli_completer_t cli_complete[] = { CLI_COMPLETE };					\
		static char command[80]="";									\
		if (cmd == CLI_INIT) {										\
		 	ast_join(command, sizeof(command), cli_command);					\
			e->command = command;								\
			e->usage = _USAGE;									\
			return NULL;										\
		} else if (cmd == CLI_GENERATE) {								\
        		uint8_t completer;									\
			for (completer=0; completer<ARRAY_LEN(cli_complete); completer++) {			\
				if ((unsigned)a->pos == (completer + ARRAY_LEN(cli_command) - 1) || _COMPLETER_REPEAT ) {\
					return sccp_exec_completer(cli_complete[completer], (char *)a->line, (char *)a->word, a->pos, a->n);\
				}										\
			}											\
			return NULL;										\
		}												\
		if (a->argc < (int)(ARRAY_LEN(cli_command)-1)) 							\
			return CLI_SHOWUSAGE;									\
														\
		static char *cli_ami_params[] = { CLI_COMMAND, CLI_AMI_PARAMS };				\
		struct message m = { 0 };									\
		size_t hdrlen; 											\
		uint8_t x;											\
                for (x = 0; x < ARRAY_LEN(cli_ami_params) && x < a->argc; x++) {				\
                        hdrlen = strlen(cli_ami_params[x]) + 2 + strlen(a->argv[x]) + 1;			\
                        m.headers[m.hdrcount] = alloca(hdrlen);							\
                        snprintf((char *) m.headers[m.hdrcount], hdrlen, "%s: %s", cli_ami_params[x], a->argv[x]);	\
                        m.hdrcount++;                                        					\
                }												\
		switch (_CALLED_FUNCTION(a->fd, NULL, NULL, NULL, a->argc, (char **) a->argv)) {		\
			case RESULT_SUCCESS: return CLI_SUCCESS;						\
			case RESULT_FAILURE: return CLI_FAILURE;						\
			case RESULT_SHOWUSAGE: return CLI_SHOWUSAGE;						\
			default: return CLI_FAILURE;								\
		}												\
	};
#    define CLI_ENTRY(_FUNCTION_NAME,_CALLED_FUNCTION,_DESCR,_USAGE, _COMPLETER_REPEAT)				\
	static char *_FUNCTION_NAME(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a) {			\
		const char *cli_command[] = { CLI_COMMAND, NULL };						\
		static sccp_cli_completer_t cli_complete[] = { CLI_COMPLETE };					\
		static char command[80]="";										\
		if (cmd == CLI_INIT) {										\
		 	ast_join(command, sizeof(command), cli_command);					\
			e->command = command;								\
			e->usage = _USAGE;									\
			return NULL;										\
		} else if (cmd == CLI_GENERATE) {								\
                        uint8_t completer;									\
			for (completer=0; completer<ARRAY_LEN(cli_complete); completer++) {			\
				if ((unsigned)a->pos == (completer + ARRAY_LEN(cli_command) -1) || _COMPLETER_REPEAT ) {\
					return sccp_exec_completer(cli_complete[completer], (char *)a->line, (char *)a->word, a->pos, a->n);\
				}										\
			}											\
			return NULL;										\
		}												\
		if (a->argc < (int)(ARRAY_LEN(cli_command)-1)) 							\
			return CLI_SHOWUSAGE;									\
														\
		switch (_CALLED_FUNCTION(a->fd, a->argc, (char **) a->argv)) {					\
			case RESULT_SUCCESS: return CLI_SUCCESS;						\
			case RESULT_FAILURE: return CLI_FAILURE;						\
			case RESULT_SHOWUSAGE: return CLI_SHOWUSAGE;						\
			default: return CLI_FAILURE;								\
		}												\
	};
#endif										/* SCCP_AST108_H_ */
