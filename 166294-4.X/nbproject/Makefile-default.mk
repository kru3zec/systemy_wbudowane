#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mainn.c "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/adc.c" "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/buttons.c" "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/lcd.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mainn.o ${OBJECTDIR}/_ext/314060433/adc.o ${OBJECTDIR}/_ext/314060433/buttons.o ${OBJECTDIR}/_ext/314060433/lcd.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mainn.o.d ${OBJECTDIR}/_ext/314060433/adc.o.d ${OBJECTDIR}/_ext/314060433/buttons.o.d ${OBJECTDIR}/_ext/314060433/lcd.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mainn.o ${OBJECTDIR}/_ext/314060433/adc.o ${OBJECTDIR}/_ext/314060433/buttons.o ${OBJECTDIR}/_ext/314060433/lcd.o

# Source Files
SOURCEFILES=mainn.c ../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/adc.c ../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/buttons.c ../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/lcd.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mainn.o: mainn.c  .generated_files/flags/default/b8e6f1ea1630923f35e2c360967b585e08d572b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainn.o.d 
	@${RM} ${OBJECTDIR}/mainn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mainn.c  -o ${OBJECTDIR}/mainn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mainn.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/adc.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/adc.c  .generated_files/flags/default/cbb3dcaeb9fd8d8837333b118668f062bfbdf0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/adc.c"  -o ${OBJECTDIR}/_ext/314060433/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/buttons.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/buttons.c  .generated_files/flags/default/d3a7874ea211c4d3486edf31cf6ff1cb7b1eb3eb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/buttons.c"  -o ${OBJECTDIR}/_ext/314060433/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/buttons.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/lcd.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/lcd.c  .generated_files/flags/default/8f0e767c888f60e336a6087420046287a9a853b2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/lcd.c"  -o ${OBJECTDIR}/_ext/314060433/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mainn.o: mainn.c  .generated_files/flags/default/e07b4a26ad6df3d83f6e5d424ff2d57eab4ebbe3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainn.o.d 
	@${RM} ${OBJECTDIR}/mainn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mainn.c  -o ${OBJECTDIR}/mainn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mainn.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/adc.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/adc.c  .generated_files/flags/default/217c9339bd7ec0186acb488bf9bb5230970d8bec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/adc.c"  -o ${OBJECTDIR}/_ext/314060433/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/adc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/buttons.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/buttons.c  .generated_files/flags/default/5f4d62ac47a0d0fc594137165ca044afee11f3d3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/buttons.c"  -o ${OBJECTDIR}/_ext/314060433/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/buttons.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/314060433/lcd.o: ../Piotr/pic24fj128ga010_pim.x\ \(3\)/pic24fj128ga010_pim.x/bsp/lcd.c  .generated_files/flags/default/c79c341e2076d3520a80193cd33799de0a089d17 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/314060433" 
	@${RM} ${OBJECTDIR}/_ext/314060433/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/314060433/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../Piotr/pic24fj128ga010_pim.x (3)/pic24fj128ga010_pim.x/bsp/lcd.c"  -o ${OBJECTDIR}/_ext/314060433/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/314060433/lcd.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/166294-4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
