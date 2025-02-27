#ifndef SAM_LEVPARTFLIP_H_
#define SAM_LEVPARTFLIP_H_

#include "visibility.h"
#include "SAM_api.h"


#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

	//
	// Levpartflip Technology Model
	//

	/** 
	 * Create a Levpartflip variable table.
	 * @param def: the set of financial model-dependent defaults to use (None, Residential, ...)
	 * @param[in,out] err: a pointer to an error object
	 */

	SAM_EXPORT typedef void * SAM_Levpartflip;

	/// verbosity level 0 or 1. Returns 1 on success
	SAM_EXPORT int SAM_Levpartflip_execute(SAM_table data, int verbosity, SAM_error* err);


	//
	// Revenue parameters
	//

	/**
	 * Set dispatch_factors_ts: Dispatch payment factor array
	 * options: None
	 * constraints: None
	 * required if: ppa_multiplier_model=1
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_dispatch_factors_ts_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set dispatch_sched_weekday: Diurnal weekday TOD periods [1..9]
	 * options: 12 x 24 matrix
	 * constraints: None
	 * required if: ppa_multiplier_model=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_dispatch_sched_weekday_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);

	/**
	 * Set dispatch_sched_weekend: Diurnal weekend TOD periods [1..9]
	 * options: 12 x 24 matrix
	 * constraints: None
	 * required if: ppa_multiplier_model=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_dispatch_sched_weekend_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);

	/**
	 * Set dispatch_tod_factors: TOD factors for periods 1 through 9
	 * options: None
	 * constraints: None
	 * required if: ppa_multiplier_model=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_dispatch_tod_factors_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set flip_target_percent: After-tax IRR target [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=11
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_flip_target_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set flip_target_year: IRR target year [Year]
	 * options: None
	 * constraints: MIN=1
	 * required if: ?=11
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_flip_target_year_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_escalation: PPA escalation rate [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_escalation_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_multiplier_model: PPA multiplier model [0/1]
	 * options: 0=diurnal,1=timestep
	 * constraints: INTEGER,MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_multiplier_model_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_price_input: PPA price in first year input [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_price_input_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set ppa_soln_max: PPA solution maximum ppa [cents/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=100
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_soln_max_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_soln_max_iterations: PPA solution maximum number of iterations
	 * options: None
	 * constraints: INTEGER,MIN=1
	 * required if: ?=100
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_soln_max_iterations_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_soln_min: PPA solution minimum ppa [cents/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_soln_min_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_soln_mode: PPA solution mode [0/1]
	 * options: 0=solve ppa,1=specify ppa
	 * constraints: INTEGER,MIN=0,MAX=1
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_soln_mode_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ppa_soln_tolerance: PPA solution tolerance
	 * options: None
	 * constraints: None
	 * required if: ?=1e-5
	 */
	SAM_EXPORT void SAM_Levpartflip_Revenue_ppa_soln_tolerance_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// FinancialParameters parameters
	//

	/**
	 * Set analysis_period: Analyis period [years]
	 * options: None
	 * constraints: INTEGER,MIN=0,MAX=50
	 * required if: ?=30
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_analysis_period_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set batt_salvage_percentage: Net pre-tax cash battery salvage value [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_batt_salvage_percentage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cost_debt_closing: Debt closing cost [$]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=250000
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_cost_debt_closing_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cost_debt_fee: Debt closing fee (% of total debt amount) [%]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=1.5
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_cost_debt_fee_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cost_other_financing: Other financing cost [$]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=150000
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_cost_other_financing_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set debt_option: Debt option [0/1]
	 * options: 0=debt percent,1=dscr
	 * constraints: INTEGER,MIN=0,MAX=1
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_debt_option_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set debt_percent: Debt percent [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=50
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_debt_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set dscr: Debt service coverage ratio
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=1.5
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_dscr_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set dscr_limit_debt_fraction: Limit debt fraction [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_dscr_limit_debt_fraction_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set dscr_maximum_debt_fraction: Maximum debt fraction [%]
	 * options: None
	 * constraints: POSITIVE
	 * required if: ?=100
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_dscr_maximum_debt_fraction_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set dscr_reserve_months: Debt service reserve account [months P&I]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=6
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_dscr_reserve_months_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip1_reserve_cost: Major equipment reserve 1 cost [$/W]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=0.25
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip1_reserve_cost_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip1_reserve_freq: Major equipment reserve 1 frequency [years]
	 * options: None
	 * constraints: INTEGER,MIN=0
	 * required if: ?=12
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip1_reserve_freq_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip2_reserve_cost: Major equipment reserve 2 cost [$/W]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip2_reserve_cost_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip2_reserve_freq: Major equipment reserve 2 frequency [years]
	 * options: None
	 * constraints: INTEGER,MIN=0
	 * required if: ?=15
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip2_reserve_freq_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip3_reserve_cost: Major equipment reserve 3 cost [$/W]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip3_reserve_cost_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip3_reserve_freq: Major equipment reserve 3 frequency [years]
	 * options: None
	 * constraints: INTEGER,MIN=0
	 * required if: ?=20
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip3_reserve_freq_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip_reserve_depr_fed: Major equipment reserve federal depreciation
	 * options: 0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom
	 * constraints: INTEGER,MIN=0,MAX=6
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip_reserve_depr_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set equip_reserve_depr_sta: Major equipment reserve state depreciation
	 * options: 0=5yr MACRS,1=15yr MACRS,2=5yr SL,3=15yr SL, 4=20yr SL,5=39yr SL,6=Custom
	 * constraints: INTEGER,MIN=0,MAX=6
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_equip_reserve_depr_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set federal_tax_rate: Federal income tax rate [%]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_federal_tax_rate_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set inflation_rate: Inflation rate [%]
	 * options: None
	 * constraints: MIN=-99
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_inflation_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set insurance_rate: Insurance rate [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_insurance_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set months_receivables_reserve: Receivables reserve months of PPA revenue [months]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_months_receivables_reserve_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set months_working_reserve: Working capital reserve months of operating costs [months]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=6
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_months_working_reserve_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set payment_option: Debt repayment option [0/1]
	 * options: 0=Equal payments (standard amortization),1=Fixed principal declining interest
	 * constraints: INTEGER,MIN=0,MAX=1
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_payment_option_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set prop_tax_assessed_decline: Assessed value annual decline [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=5
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_prop_tax_assessed_decline_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set prop_tax_cost_assessed_percent: Percent of pre-financing costs assessed [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=95
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_prop_tax_cost_assessed_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set property_tax_rate: Property tax rate [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_property_tax_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set real_discount_rate: Real discount rate [%]
	 * options: None
	 * constraints: MIN=-99
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_real_discount_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set reserves_interest: Interest on reserves [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=1.75
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_reserves_interest_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set salvage_percentage: Net pre-tax cash salvage value [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=10
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_salvage_percentage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set state_tax_rate: State income tax rate [%]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_state_tax_rate_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set system_capacity: System nameplate capacity [kW]
	 * options: None
	 * constraints: POSITIVE
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_system_capacity_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set system_heat_rate: System heat rate [MMBTus/MWh]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_system_heat_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set term_int_rate: Term financing interest rate [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=8.5
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_term_int_rate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set term_tenor: Term financing period [years]
	 * options: None
	 * constraints: INTEGER,MIN=0
	 * required if: ?=10
	 */
	SAM_EXPORT void SAM_Levpartflip_FinancialParameters_term_tenor_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// SystemCosts parameters
	//

	/**
	 * Set add_om_num_types: Number of O and M types
	 * options: battery,fuelcell
	 * constraints: INTEGER,MIN=0,MAX=2
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_add_om_num_types_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set annual_fuel_usage: Fuel usage (yr 1) [kWht]
	 * options: generic_system,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical
	 * constraints: MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_annual_fuel_usage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set annual_fuel_usage_lifetime: Fuel usage (lifetime) [kWht]
	 * options: generic_system,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_annual_fuel_usage_lifetime_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_batt_capacity_cost: Battery capacity-based System Costs amount [$/kWcap]
	 * options: battery
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_batt_capacity_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_batt_fixed_cost: Battery fixed System Costs annual amount [$/year]
	 * options: battery
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_batt_fixed_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_batt_nameplate: Battery capacity for System Costs values [kW]
	 * options: battery
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_batt_nameplate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_batt_replacement_cost: Replacement cost 1 [$/kWh]
	 * options: battery
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_batt_replacement_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_batt_variable_cost: Battery production-based System Costs amount [$/MWh]
	 * options: battery
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_batt_variable_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_capacity: Capacity-based O&M amount [$/kWcap]
	 * options: !battery,!fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_capacity_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_capacity_escal: Capacity-based O&M escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_capacity_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_fixed: Fixed O&M annual amount [$/year]
	 * options: !battery,!fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fixed_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_fixed_escal: Fixed O&M escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fixed_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_fuel_cost: Fuel cost [$/MMBtu]
	 * options: generic_system,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuel_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_fuel_cost_escal: Fuel cost escalation [%/year]
	 * options: generic_system,fuelcell,tcslinearfresnel,tcstroughempirical,tcsgenericsolar,fresnelphysical
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuel_cost_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_fuelcell_capacity_cost: Fuel cell capacity-based System Costs amount [$/kWcap]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuelcell_capacity_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_fuelcell_fixed_cost: Fuel cell fixed System Costs annual amount [$/year]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuelcell_fixed_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_fuelcell_nameplate: Fuel cell capacity for System Costs values [kW]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuelcell_nameplate_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_fuelcell_replacement_cost: Replacement cost 2 [$/kW]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuelcell_replacement_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_fuelcell_variable_cost: Fuel cell production-based System Costs amount [$/MWh]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_fuelcell_variable_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_opt_fuel_1_cost: Biomass feedstock cost [$/unit]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_1_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_opt_fuel_1_cost_escal: Biomass feedstock cost escalation [%/year]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_1_cost_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_opt_fuel_1_usage: Biomass feedstock usage [unit]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_1_usage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_opt_fuel_2_cost: Coal feedstock cost [$/unit]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_2_cost_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_opt_fuel_2_cost_escal: Coal feedstock cost escalation [%/year]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_2_cost_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_opt_fuel_2_usage: Coal feedstock usage [unit]
	 * options: biomass
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_opt_fuel_2_usage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_production: Production-based O&M amount [$/MWh]
	 * options: !battery,!fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_production_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_production1_values: Battery production for System Costs values [kWh]
	 * options: battery
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_production1_values_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_production2_values: Fuel cell production for System Costs values [kWh]
	 * options: fuelcell
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_production2_values_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_production_escal: Production-based O&M escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_production_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_replacement_cost_escal: Replacement cost escalation [%/year]
	 * options: battery,fuelcell
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_om_replacement_cost_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set total_installed_cost: Installed cost [$]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemCosts_total_installed_cost_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// LandLease parameters
	//

	/**
	 * Set land_area: Total land area [acres]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_LandLease_land_area_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set om_land_lease: Land lease cost [$/acre]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_LandLease_om_land_lease_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set om_land_lease_escal: Land lease cost escalation [%/yr]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_LandLease_om_land_lease_escal_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// TaxCreditIncentives parameters
	//

	/**
	 * Set itc_fed_amount: Federal amount-based ITC amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set itc_fed_amount_deprbas_fed: Federal amount-based ITC reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_fed_amount_deprbas_sta: Federal amount-based ITC reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_fed_percent: Federal percentage-based ITC percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set itc_fed_percent_deprbas_fed: Federal percentage-based ITC reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_fed_percent_deprbas_sta: Federal percentage-based ITC reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_fed_percent_maxvalue: Federal percentage-based ITC maximum value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_maxvalue_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set itc_sta_amount: State amount-based ITC amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set itc_sta_amount_deprbas_fed: State amount-based ITC reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_sta_amount_deprbas_sta: State amount-based ITC reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_sta_percent: State percentage-based ITC percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set itc_sta_percent_deprbas_fed: State percentage-based ITC reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_sta_percent_deprbas_sta: State percentage-based ITC reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set itc_sta_percent_maxvalue: State percentage-based ITC maximum Value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_maxvalue_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set ptc_fed_amount: Federal PTC amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_fed_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set ptc_fed_escal: Federal PTC escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_fed_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ptc_fed_term: Federal PTC term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=10
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_fed_term_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ptc_sta_amount: State PTC amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_sta_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set ptc_sta_escal: State PTC escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_sta_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ptc_sta_term: State PTC term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=10
	 */
	SAM_EXPORT void SAM_Levpartflip_TaxCreditIncentives_ptc_sta_term_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// Depreciation parameters
	//

	/**
	 * Set depr_alloc_custom_percent: Custom depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_custom_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_macrs_15_percent: 15-yr MACRS depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=1.5
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_macrs_15_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_macrs_5_percent: 5-yr MACRS depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=89
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_macrs_5_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_sl_15_percent: 15-yr straight line depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=3
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_sl_15_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_sl_20_percent: 20-yr straight line depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=3
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_sl_20_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_sl_39_percent: 39-yr straight line depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0.5
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_sl_39_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_alloc_sl_5_percent: 5-yr straight line depreciation federal and state allocation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_alloc_sl_5_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed: Federal bonus depreciation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_custom: Federal bonus depreciation custom [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_custom_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_macrs_15: Federal bonus depreciation 15-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_macrs_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_macrs_5: Federal bonus depreciation 5-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_macrs_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_sl_15: Federal bonus depreciation 15-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_sl_20: Federal bonus depreciation 20-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_20_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_sl_39: Federal bonus depreciation 39-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_39_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_fed_sl_5: Federal bonus depreciation 5-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta: State bonus depreciation [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_custom: State bonus depreciation custom [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_custom_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_macrs_15: State bonus depreciation 15-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_macrs_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_macrs_5: State bonus depreciation 5-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_macrs_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_sl_15: State bonus depreciation 15-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_sl_20: State bonus depreciation 20-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_20_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_sl_39: State bonus depreciation 39-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_39_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_bonus_sta_sl_5: State bonus depreciation 5-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_custom_schedule: Custom depreciation schedule [%]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_custom_schedule_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set depr_fedbas_method: Method of federal depreciation reduction
	 * options: 0=5yr MACRS,1=Proportional
	 * constraints: INTEGER,MIN=0,MAX=1
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_fedbas_method_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_custom: Federal ITC depreciation custom [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_custom_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_macrs_15: Federal ITC depreciation 15-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_macrs_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_macrs_5: Federal ITC depreciation 5-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_macrs_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_sl_15: Federal ITC depreciation 15-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_sl_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_sl_20: Federal ITC depreciation 20-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_sl_20_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_sl_39: Federal ITC depreciation 39-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_sl_39_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_fed_sl_5: Federal ITC depreciation 5-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_fed_sl_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_custom: State ITC depreciation custom [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_custom_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_macrs_15: State ITC depreciation 15-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_macrs_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_macrs_5: State ITC depreciation 5-yr MACRS [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_macrs_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_sl_15: State ITC depreciation 15-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_sl_15_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_sl_20: State ITC depreciation 20-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_sl_20_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_sl_39: State ITC depreciation 39-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_sl_39_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_itc_sta_sl_5: State ITC depreciation 5-yr straight line [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_itc_sta_sl_5_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set depr_stabas_method: Method of state depreciation reduction
	 * options: 0=5yr MACRS,1=Proportional
	 * constraints: INTEGER,MIN=0,MAX=1
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Depreciation_depr_stabas_method_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// PaymentIncentives parameters
	//

	/**
	 * Set cbi_fed_amount: Federal CBI amount [$/Watt]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_fed_deprbas_fed: Federal CBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_fed_deprbas_sta: Federal CBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_fed_maxvalue: Federal CBI maximum [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_fed_tax_fed: Federal CBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_fed_tax_sta: Federal CBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_fed_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_amount: Other CBI amount [$/Watt]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_deprbas_fed: Other CBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_deprbas_sta: Other CBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_maxvalue: Other CBI maximum [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_tax_fed: Other CBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_oth_tax_sta: Other CBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_oth_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_amount: State CBI amount [$/Watt]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_deprbas_fed: State CBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_deprbas_sta: State CBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_maxvalue: State CBI maximum [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_tax_fed: State CBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_sta_tax_sta: State CBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_sta_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_amount: Utility CBI amount [$/Watt]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_deprbas_fed: Utility CBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_deprbas_sta: Utility CBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_maxvalue: Utility CBI maximum [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_tax_fed: Utility CBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cbi_uti_tax_sta: Utility CBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_cbi_uti_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_amount: Federal amount-based IBI amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_amount_deprbas_fed: Federal amount-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_amount_deprbas_sta: Federal amount-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_amount_tax_fed: Federal amount-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_amount_tax_sta: Federal amount-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent: Federal percentage-based IBI percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent_deprbas_fed: Federal percentage-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent_deprbas_sta: Federal percentage-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent_maxvalue: Federal percentage-based IBI maximum value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent_tax_fed: Federal percentage-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_fed_percent_tax_sta: Federal percentage-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_amount: Other amount-based IBI amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_amount_deprbas_fed: Other amount-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_amount_deprbas_sta: Other amount-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_amount_tax_fed: Other amount-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_amount_tax_sta: Other amount-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent: Other percentage-based IBI percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent_deprbas_fed: Other percentage-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent_deprbas_sta: Other percentage-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent_maxvalue: Other percentage-based IBI maximum value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent_tax_fed: Other percentage-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_oth_percent_tax_sta: Other percentage-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_amount: State amount-based IBI amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_amount_deprbas_fed: State amount-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_amount_deprbas_sta: State amount-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_amount_tax_fed: State amount-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_amount_tax_sta: State amount-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent: State percentage-based IBI percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent_deprbas_fed: State percentage-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent_deprbas_sta: State percentage-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent_maxvalue: State percentage-based IBI maximum value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent_tax_fed: State percentage-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_sta_percent_tax_sta: State percentage-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_amount: Utility amount-based IBI amount [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_amount_deprbas_fed: Utility amount-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_amount_deprbas_sta: Utility amount-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_amount_tax_fed: Utility amount-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_amount_tax_sta: Utility amount-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent: Utility percentage-based IBI percent [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent_deprbas_fed: Utility percentage-based IBI reduces federal depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_deprbas_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent_deprbas_sta: Utility percentage-based IBI reduces state depreciation basis [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_deprbas_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent_maxvalue: Utility percentage-based IBI maximum value [$]
	 * options: None
	 * constraints: None
	 * required if: ?=1e99
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_maxvalue_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent_tax_fed: Utility percentage-based IBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set ibi_uti_percent_tax_sta: Utility percentage-based IBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_fed_amount: Federal PBI amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set pbi_fed_escal: Federal PBI escalation [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_fed_for_ds: Federal PBI available for debt service [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_for_ds_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_fed_tax_fed: Federal PBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_fed_tax_sta: Federal PBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_fed_term: Federal PBI term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_fed_term_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_oth_amount: Other PBI amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set pbi_oth_escal: Other PBI escalation [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_oth_for_ds: Other PBI available for debt service [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_for_ds_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_oth_tax_fed: Other PBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_oth_tax_sta: Other PBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_oth_term: Other PBI term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_oth_term_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_sta_amount: State PBI amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set pbi_sta_escal: State PBI escalation [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_sta_for_ds: State PBI available for debt service [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_for_ds_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_sta_tax_fed: State PBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_sta_tax_sta: State PBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_sta_term: State PBI term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_sta_term_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_uti_amount: Utility PBI amount [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_amount_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set pbi_uti_escal: Utility PBI escalation [%]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_escal_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_uti_for_ds: Utility PBI available for debt service [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_for_ds_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_uti_tax_fed: Utility PBI federal taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_tax_fed_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_uti_tax_sta: Utility PBI state taxable [0/1]
	 * options: None
	 * constraints: BOOLEAN
	 * required if: ?=1
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_tax_sta_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set pbi_uti_term: Utility PBI term [years]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_PaymentIncentives_pbi_uti_term_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// SystemOutput parameters
	//

	/**
	 * Set degradation: Annual energy degradation
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemOutput_degradation_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set gen: Power generated by renewable resource [kW]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemOutput_gen_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set gen_purchases: Electricity from grid to system [kW]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemOutput_gen_purchases_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set system_capacity: System nameplate capacity [kW]
	 * options: None
	 * constraints: MIN=1e-3
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_SystemOutput_system_capacity_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// ElectricityRates parameters
	//

	/**
	 * Set en_electricity_rates: Enable electricity rates for grid purchase [0/1]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_ElectricityRates_en_electricity_rates_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set rate_escalation: Annual electricity rate escalation [%/year]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_ElectricityRates_rate_escalation_aset(SAM_table ptr, double* arr, int length, SAM_error *err);


	//
	// Moratorium parameters
	//

	/**
	 * Set loan_moratorium: Loan moratorium period [years]
	 * options: None
	 * constraints: INTEGER,MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Moratorium_loan_moratorium_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// Recapitalization parameters
	//

	/**
	 * Set system_lifetime_recapitalize: Recapitalization boolean
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Recapitalization_system_lifetime_recapitalize_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set system_recapitalization_cost: Recapitalization cost [$]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Recapitalization_system_recapitalization_cost_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set system_recapitalization_escalation: Recapitalization escalation (above inflation) [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Recapitalization_system_recapitalization_escalation_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set system_use_recapitalization: Recapitalization expenses [0/1]
	 * options: 0=None,1=Recapitalize
	 * constraints: INTEGER,MIN=0
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_Recapitalization_system_use_recapitalization_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// TimeOfDelivery parameters
	//

	/**
	 * Set system_use_lifetime_output: Lifetime hourly system outputs [0/1]
	 * options: 0=hourly first year,1=hourly lifetime
	 * constraints: INTEGER,MIN=0
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_TimeOfDelivery_system_use_lifetime_output_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// UtilityBill parameters
	//

	/**
	 * Set utility_bill_w_sys: Electricity bill with system [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_UtilityBill_utility_bill_w_sys_aset(SAM_table ptr, double* arr, int length, SAM_error *err);


	//
	// ConstructionFinancing parameters
	//

	/**
	 * Set construction_financing_cost: Construction financing total [$]
	 * options: None
	 * constraints: None
	 * required if: *
	 */
	SAM_EXPORT void SAM_Levpartflip_ConstructionFinancing_construction_financing_cost_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// OtherCapitalCosts parameters
	//

	/**
	 * Set cost_dev_fee_percent: Development fee (% pre-financing cost) [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=3
	 */
	SAM_EXPORT void SAM_Levpartflip_OtherCapitalCosts_cost_dev_fee_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set cost_equity_closing: Equity closing cost [$]
	 * options: None
	 * constraints: MIN=0
	 * required if: ?=100000
	 */
	SAM_EXPORT void SAM_Levpartflip_OtherCapitalCosts_cost_equity_closing_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// IRRTargets parameters
	//

	/**
	 * Set tax_investor_equity_percent: Investor equity [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=98
	 */
	SAM_EXPORT void SAM_Levpartflip_IRRTargets_tax_investor_equity_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set tax_investor_postflip_cash_percent: Investor post-flip cash  [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=15
	 */
	SAM_EXPORT void SAM_Levpartflip_IRRTargets_tax_investor_postflip_cash_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set tax_investor_postflip_tax_percent: Investor post-flip tax benefit  [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=15
	 */
	SAM_EXPORT void SAM_Levpartflip_IRRTargets_tax_investor_postflip_tax_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set tax_investor_preflip_cash_percent: Investor pre-flip cash  [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=98
	 */
	SAM_EXPORT void SAM_Levpartflip_IRRTargets_tax_investor_preflip_cash_percent_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set tax_investor_preflip_tax_percent: Investor pre-flip tax benefit  [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=98
	 */
	SAM_EXPORT void SAM_Levpartflip_IRRTargets_tax_investor_preflip_tax_percent_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// LCOS parameters
	//

	/**
	 * Set batt_annual_charge_energy: Battery annual energy charged [kWh]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_batt_annual_charge_energy_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set batt_annual_charge_from_system: Battery annual energy charged from system [kWh]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_batt_annual_charge_from_system_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set batt_annual_discharge_energy: Battery annual energy discharged [kWh]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_batt_annual_discharge_energy_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set batt_capacity_percent: Battery relative capacity to nameplate [%]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_batt_capacity_percent_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set batt_salvage_percentage: Net pre-tax cash battery salvage value [%]
	 * options: None
	 * constraints: MIN=0,MAX=100
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_batt_salvage_percentage_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set battery_total_cost_lcos: Battery total investment cost [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_battery_total_cost_lcos_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set charge_w_sys_ec_ym: Energy charge with system [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_charge_w_sys_ec_ym_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);

	/**
	 * Set grid_to_batt: Electricity to grid from battery [kW]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_grid_to_batt_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set monthly_batt_to_grid: Energy to grid from battery [kWh]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_monthly_batt_to_grid_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set monthly_grid_to_batt: Energy to battery from grid [kWh]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_monthly_grid_to_batt_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set monthly_grid_to_load: Energy to load from grid [kWh]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_monthly_grid_to_load_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set monthly_system_to_grid: Energy to grid from system [kWh]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_monthly_system_to_grid_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set true_up_credits_ym: Net annual true-up payments [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_true_up_credits_ym_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);

	/**
	 * Set year1_monthly_ec_charge_gross_with_system: Energy charge with system before credits [$/mo]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_year1_monthly_ec_charge_gross_with_system_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set year1_monthly_ec_charge_with_system: Energy charge with system [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_year1_monthly_ec_charge_with_system_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set year1_monthly_electricity_to_grid: Electricity to/from grid [kWh/mo]
	 * options: None
	 * constraints: LENGTH=12
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_LCOS_year1_monthly_electricity_to_grid_aset(SAM_table ptr, double* arr, int length, SAM_error *err);


	//
	// ChargesByMonth parameters
	//

	/**
	 * Set net_billing_credits_ym: Net billing credit [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_ChargesByMonth_net_billing_credits_ym_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);

	/**
	 * Set nm_dollars_applied_ym: Net metering credit [$]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_ChargesByMonth_nm_dollars_applied_ym_mset(SAM_table ptr, double* mat, int nrows, int ncols, SAM_error *err);


	//
	// BatterySystem parameters
	//

	/**
	 * Set batt_bank_replacement: Battery bank replacements per year [number/year]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_batt_bank_replacement_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set batt_computed_bank_capacity: Battery bank capacity [kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_batt_computed_bank_capacity_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set batt_replacement_option: Enable battery replacement? [0=none,1=capacity based,2=user schedule]
	 * options: None
	 * constraints: INTEGER,MIN=0,MAX=2
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_batt_replacement_option_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set batt_replacement_schedule_percent: Percentage of battery capacity to replace in each year [%]
	 * options: length <= analysis_period
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_batt_replacement_schedule_percent_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set battery_per_kWh: Battery cost [$/kWh]
	 * options: None
	 * constraints: None
	 * required if: ?=0.0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_battery_per_kWh_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set en_batt: Enable battery storage model [0/1]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_en_batt_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set en_standalone_batt: Enable standalone battery storage model [0/1]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_en_standalone_batt_nset(SAM_table ptr, double number, SAM_error *err);

	/**
	 * Set en_wave_batt: Enable standalone battery storage model [0/1]
	 * options: None
	 * constraints: None
	 * required if: ?=0
	 */
	SAM_EXPORT void SAM_Levpartflip_BatterySystem_en_wave_batt_nset(SAM_table ptr, double number, SAM_error *err);


	//
	// FuelCell parameters
	//

	/**
	 * Set annual_fuel_usage_lifetime: Annual Fuel Usage (lifetime) [kWht]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_FuelCell_annual_fuel_usage_lifetime_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set fuelcell_annual_energy_discharged: Fuel cell annual energy discharged [kWh]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_FuelCell_fuelcell_annual_energy_discharged_aset(SAM_table ptr, double* arr, int length, SAM_error *err);

	/**
	 * Set fuelcell_replacement: Fuel cell replacements per year [number/year]
	 * options: None
	 * constraints: None
	 * required if: None
	 */
	SAM_EXPORT void SAM_Levpartflip_FuelCell_fuelcell_replacement_aset(SAM_table ptr, double* arr, int length, SAM_error *err);


	/**
	 * Revenue Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_Revenue_dispatch_factors_ts_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Revenue_dispatch_sched_weekday_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Revenue_dispatch_sched_weekend_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Revenue_dispatch_tod_factors_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_flip_target_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_flip_target_year_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_escalation_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_multiplier_model_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Revenue_ppa_price_input_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_soln_max_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_soln_max_iterations_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_soln_min_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_soln_mode_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Revenue_ppa_soln_tolerance_nget(SAM_table ptr, SAM_error *err);


	/**
	 * FinancialParameters Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_analysis_period_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_batt_salvage_percentage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_cost_debt_closing_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_cost_debt_fee_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_cost_other_financing_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_debt_option_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_debt_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_dscr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_dscr_limit_debt_fraction_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_dscr_maximum_debt_fraction_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_dscr_reserve_months_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip1_reserve_cost_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip1_reserve_freq_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip2_reserve_cost_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip2_reserve_freq_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip3_reserve_cost_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip3_reserve_freq_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip_reserve_depr_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_equip_reserve_depr_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_FinancialParameters_federal_tax_rate_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_inflation_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_insurance_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_months_receivables_reserve_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_months_working_reserve_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_payment_option_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_prop_tax_assessed_decline_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_prop_tax_cost_assessed_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_property_tax_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_real_discount_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_reserves_interest_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_salvage_percentage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_FinancialParameters_state_tax_rate_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_system_capacity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_system_heat_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_term_int_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_FinancialParameters_term_tenor_nget(SAM_table ptr, SAM_error *err);


	/**
	 * SystemCosts Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_add_om_num_types_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_annual_fuel_usage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_annual_fuel_usage_lifetime_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_batt_capacity_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_batt_fixed_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_batt_nameplate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_batt_replacement_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_batt_variable_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_capacity_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_capacity_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fixed_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_fixed_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fuel_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_fuel_cost_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fuelcell_capacity_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fuelcell_fixed_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_fuelcell_nameplate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fuelcell_replacement_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_fuelcell_variable_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_opt_fuel_1_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_opt_fuel_1_cost_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_opt_fuel_1_usage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_opt_fuel_2_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_opt_fuel_2_cost_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_opt_fuel_2_usage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_production_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_production1_values_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemCosts_om_production2_values_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_production_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_om_replacement_cost_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemCosts_total_installed_cost_nget(SAM_table ptr, SAM_error *err);


	/**
	 * LandLease Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_LandLease_land_area_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LandLease_om_land_lease_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_LandLease_om_land_lease_escal_nget(SAM_table ptr, SAM_error *err);


	/**
	 * TaxCreditIncentives Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_fed_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_fed_percent_maxvalue_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_sta_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_itc_sta_percent_maxvalue_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_ptc_fed_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_ptc_fed_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_ptc_fed_term_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_TaxCreditIncentives_ptc_sta_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_ptc_sta_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_TaxCreditIncentives_ptc_sta_term_nget(SAM_table ptr, SAM_error *err);


	/**
	 * Depreciation Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_custom_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_macrs_15_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_macrs_5_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_sl_15_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_sl_20_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_sl_39_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_alloc_sl_5_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_fed_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_bonus_sta_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Depreciation_depr_custom_schedule_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_fedbas_method_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_fed_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_itc_sta_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Depreciation_depr_stabas_method_nget(SAM_table ptr, SAM_error *err);


	/**
	 * PaymentIncentives Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_fed_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_oth_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_sta_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_cbi_uti_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_amount_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_fed_percent_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_amount_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_oth_percent_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_amount_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_sta_percent_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_amount_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_deprbas_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_deprbas_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_maxvalue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_ibi_uti_percent_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_PaymentIncentives_pbi_fed_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_fed_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_fed_for_ds_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_fed_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_fed_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_fed_term_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_PaymentIncentives_pbi_oth_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_oth_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_oth_for_ds_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_oth_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_oth_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_oth_term_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_PaymentIncentives_pbi_sta_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_sta_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_sta_for_ds_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_sta_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_sta_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_sta_term_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_PaymentIncentives_pbi_uti_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_uti_escal_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_uti_for_ds_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_uti_tax_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_uti_tax_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_PaymentIncentives_pbi_uti_term_nget(SAM_table ptr, SAM_error *err);


	/**
	 * SystemOutput Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_SystemOutput_degradation_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemOutput_gen_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_SystemOutput_gen_purchases_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_SystemOutput_system_capacity_nget(SAM_table ptr, SAM_error *err);


	/**
	 * ElectricityRates Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_ElectricityRates_en_electricity_rates_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_ElectricityRates_rate_escalation_aget(SAM_table ptr, int* length, SAM_error *err);


	/**
	 * Moratorium Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_Moratorium_loan_moratorium_nget(SAM_table ptr, SAM_error *err);


	/**
	 * Recapitalization Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_Recapitalization_system_lifetime_recapitalize_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Recapitalization_system_recapitalization_cost_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Recapitalization_system_recapitalization_escalation_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Recapitalization_system_use_recapitalization_nget(SAM_table ptr, SAM_error *err);


	/**
	 * TimeOfDelivery Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_TimeOfDelivery_system_use_lifetime_output_nget(SAM_table ptr, SAM_error *err);


	/**
	 * UtilityBill Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_UtilityBill_utility_bill_w_sys_aget(SAM_table ptr, int* length, SAM_error *err);


	/**
	 * ConstructionFinancing Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_ConstructionFinancing_construction_financing_cost_nget(SAM_table ptr, SAM_error *err);


	/**
	 * OtherCapitalCosts Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_OtherCapitalCosts_cost_dev_fee_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_OtherCapitalCosts_cost_equity_closing_nget(SAM_table ptr, SAM_error *err);


	/**
	 * IRRTargets Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_IRRTargets_tax_investor_equity_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_IRRTargets_tax_investor_postflip_cash_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_IRRTargets_tax_investor_postflip_tax_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_IRRTargets_tax_investor_preflip_cash_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_IRRTargets_tax_investor_preflip_tax_percent_nget(SAM_table ptr, SAM_error *err);


	/**
	 * LCOS Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_LCOS_batt_annual_charge_energy_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_batt_annual_charge_from_system_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_batt_annual_discharge_energy_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_batt_capacity_percent_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_LCOS_batt_salvage_percentage_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_LCOS_battery_total_cost_lcos_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_charge_w_sys_ec_ym_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_grid_to_batt_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_monthly_batt_to_grid_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_monthly_grid_to_batt_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_monthly_grid_to_load_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_monthly_system_to_grid_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_true_up_credits_ym_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_year1_monthly_ec_charge_gross_with_system_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_year1_monthly_ec_charge_with_system_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_LCOS_year1_monthly_electricity_to_grid_aget(SAM_table ptr, int* length, SAM_error *err);


	/**
	 * ChargesByMonth Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_ChargesByMonth_net_billing_credits_ym_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_ChargesByMonth_nm_dollars_applied_ym_mget(SAM_table ptr, int* nrows, int* ncols, SAM_error *err);


	/**
	 * BatterySystem Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_BatterySystem_batt_bank_replacement_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_batt_computed_bank_capacity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_batt_replacement_option_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_BatterySystem_batt_replacement_schedule_percent_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_battery_per_kWh_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_en_batt_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_en_standalone_batt_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_BatterySystem_en_wave_batt_nget(SAM_table ptr, SAM_error *err);


	/**
	 * FuelCell Getters
	 */

	SAM_EXPORT double* SAM_Levpartflip_FuelCell_annual_fuel_usage_lifetime_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_FuelCell_fuelcell_annual_energy_discharged_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_FuelCell_fuelcell_replacement_aget(SAM_table ptr, int* length, SAM_error *err);


	/**
	 * Outputs Getters
	 */

	SAM_EXPORT double SAM_Levpartflip_Outputs_adjusted_installed_cost_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_analysis_period_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cash_for_debt_service_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_fedtax_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_statax_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_total_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_total_oth_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_total_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cbi_total_uti_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_annual_cost_lcos_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_annual_costs_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_annual_discharge_lcos_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_battery_replacement_cost_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_battery_replacement_cost_schedule_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_cash_for_ds_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_charging_cost_grid_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_charging_cost_grid_month_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_charging_cost_pv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_debt_balance_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_debt_payment_interest_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_debt_payment_principal_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_debt_payment_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_debt_size_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_debtservice_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_equip1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_equip2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_equip3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_om_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_disbursement_receivables_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_ebitda_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_effective_tax_frac_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_net_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_purchases_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_apr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_aug_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dec_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch4_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch6_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch7_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch8_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_dispatch9_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_feb_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_jan_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_jul_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_jun_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_mar_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_may_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD4_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD6_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD7_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD8_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_monthly_firstyear_TOD9_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_nov_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_oct_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_sales_sep_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_value_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_energy_without_battery_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_custom_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_macrs_15_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_macrs_5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_me1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_me2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_me3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_sl_15_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_sl_20_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_sl_39_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_sl_5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_feddepr_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_federal_tax_frac_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_fedtax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_fedtax_income_prior_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_fedtax_income_with_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_fedtax_taxable_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_debtservice_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_equip1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_equip2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_equip3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_om_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_funding_receivables_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_insurance_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_fed_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_fed_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_fed_percent_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_sta_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_sta_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_sta_percent_amount_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_itc_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_land_lease_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cf_length_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_net_salvage_value_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_batt_capacity_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_batt_fixed_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_capacity1_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_capacity2_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_capacity_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_fixed1_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_fixed2_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_fixed_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_fuel_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_opt_fuel_1_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_opt_fuel_2_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_production1_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_production2_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_om_production_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_operating_expenses_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_fedtax_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_statax_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_total_fed_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_total_oth_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_total_sta_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pbi_total_uti_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_ppa_price_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pretax_cashflow_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pretax_dscr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_dsra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_financing_activities_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_investing_activities_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me1cs_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me1ra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me2cs_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me2ra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me3cs_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_me3ra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_mecs_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_operating_activities_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_ra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_receivablesra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_aftertax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_aftertax_cash_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_aftertax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_aftertax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_pretax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_pretax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_return_pretax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_project_wcra_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_property_tax_assessed_value_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_property_tax_expense_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_ptc_fed_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_ptc_sta_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pv_cash_for_ds_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_pv_interest_factor_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_recapitalization_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_debtservice_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_equip1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_equip2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_equip3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_interest_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_om_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_receivables_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_reserve_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_apr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_aug_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dec_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch4_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch6_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch7_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch8_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_dispatch9_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_feb_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_jan_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_jul_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_jun_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_mar_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_may_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD4_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD6_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD7_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD8_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_monthly_firstyear_TOD9_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_nov_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_oct_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_revenue_sep_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_salvage_cost_lcos_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_cash_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_itc_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_ptc_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_aftertax_tax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_pretax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_pretax_cash_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_pretax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_sponsor_pretax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_custom_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_macrs_15_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_macrs_5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_me1_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_me2_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_me3_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_sl_15_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_sl_20_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_sl_39_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_sl_5_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_stadepr_total_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_statax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_statax_income_prior_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_statax_income_with_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_statax_taxable_incentives_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_state_tax_frac_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_cash_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_itc_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_max_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_ptc_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_aftertax_tax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_pretax_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_pretax_irr_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_tax_investor_pretax_npv_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_total_revenue_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_util_escal_rate_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_cf_utility_bill_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cost_debt_upfront_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cost_financing_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cost_installed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cost_installedperwatt_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_cost_prefinancing_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_debt_fraction_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_none_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_none_percent_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_alloc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_after_itc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_cbi_reduc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_first_year_bonus_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_fixed_amount_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_ibi_reduc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_fed_reduction_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_itc_sta_reduction_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_amount_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_qual_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_prior_itc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_fedbas_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_after_itc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_cbi_reduc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_first_year_bonus_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_fixed_amount_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_ibi_reduc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_fed_reduction_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_itc_sta_reduction_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_amount_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_qual_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_prior_itc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_depr_stabas_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_effective_tax_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch1_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch2_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch3_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch4_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch6_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch7_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch8_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_dispatch9_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price1_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price2_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price3_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price4_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price6_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price7_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price8_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_energy_price9_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch1_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch2_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch3_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch4_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch6_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch7_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch8_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_firstyear_revenue_dispatch9_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_flip_actual_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_flip_actual_year_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_flip_target_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_flip_target_year_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_fedtax_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_statax_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_total_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_total_oth_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_total_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ibi_total_uti_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_issuance_of_equity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_fixed_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_fed_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_fixed_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_disallow_sta_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_fixed_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_fed_qual_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_fixed_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_percent_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_custom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_macrs_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_macrs_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_sl_15_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_sl_20_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_sl_39_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_sl_5_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_sta_qual_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_total_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_total_fed_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_itc_total_sta_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoe_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoe_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoptc_fed_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoptc_fed_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoptc_sta_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcoptc_sta_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcos_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lcos_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lppa_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_lppa_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_min_dscr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_nominal_discount_rate_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_annual_costs_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_annual_costs_lcos_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_energy_lcos_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_energy_lcos_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_energy_nom_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_energy_real_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_npv_ppa_revenue_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ppa_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ppa_escalation_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double* SAM_Levpartflip_Outputs_ppa_multipliers_aget(SAM_table ptr, int* length, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_ppa_price_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_pre_depr_alloc_basis_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_pre_itc_qual_basis_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_present_value_fuel_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_present_value_insandproptax_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_present_value_oandm_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_present_value_oandm_nonfuel_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_prop_tax_assessed_value_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_purchase_of_property_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_pv_cafds_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_salvage_value_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_size_of_debt_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_size_of_equity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_aftertax_development_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_aftertax_equity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_aftertax_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_aftertax_npv_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_pretax_development_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_pretax_equity_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_pretax_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_sponsor_pretax_npv_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_tax_investor_aftertax_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_tax_investor_aftertax_npv_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_tax_investor_pretax_irr_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_tax_investor_pretax_npv_nget(SAM_table ptr, SAM_error *err);

	SAM_EXPORT double SAM_Levpartflip_Outputs_wacc_nget(SAM_table ptr, SAM_error *err);

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#endif